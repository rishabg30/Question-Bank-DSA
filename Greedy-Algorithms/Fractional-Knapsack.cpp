#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/fractional-knapsack_975286?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void printArray_1D(vector<int>&arr) {
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << endl;
}

void printArray_2D(vector<vector<int>>&arr) {
	for (auto it : arr) {
		for (auto it2 : it) {
			cout << it2 << " ";
		}
		cout << endl;
	}
}

double maximumValue (vector<pair<int, int>>&items, int n, int w) {
	// {value_to_weight_ratio , {weight,value}}
	vector<pair<double, pair<double, double>>>value_to_weight_ratio;
	for (int i = 0; i < n; i++) {
		pair<int, int>p1 = items[i];

		double value_to_weight = ((p1.second) * (1.0)) / ((p1.first) * (1.0));
		value_to_weight_ratio.push_back(make_pair(value_to_weight, make_pair(p1.first, p1.second)));
	}
	sort(value_to_weight_ratio.begin(), value_to_weight_ratio.end());
	double myValue = 0.0;
	for (int i = n - 1; i >= 0; i--) {
		if (w >= value_to_weight_ratio[i].second.first) {
			w -= value_to_weight_ratio[i].second.first;
			myValue += value_to_weight_ratio[i].second.second;
		}
		else if (w != 0 && w < value_to_weight_ratio[i].second.first) {
			double rem_value = ((w * (1.0)) * (value_to_weight_ratio[i].second.second) * (1.0));
			rem_value /= ((value_to_weight_ratio[i].second.first) * (1.0));
			myValue += rem_value;
			w = 0;
		}
		else {
			break;
		}
	}
	return myValue;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int w; cin >> w;
	vector<pair<int, int>>items;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		items.push_back(make_pair(x, y));
	}
	cout << maximumValue(items, n, w) << endl;
}