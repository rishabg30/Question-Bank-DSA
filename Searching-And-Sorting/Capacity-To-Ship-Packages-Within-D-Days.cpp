#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

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

bool check(int mid, vector<int>&weights, int days) {
	int curr_weight = 0;
	for (int i = 0; i < weights.size();) {
		if (curr_weight + weights[i] <= mid) {
			curr_weight += weights[i];
			i++;
		}
		else {
			curr_weight = 0;
			days--;
		}
		if (days == 0)return false;
	}
	return true;
}
int shipWithinDays(vector<int>& weights, int days) {
	//Search space[0.....sum_of_weights_of_package]
	int low = 1, high = 0;
	for (int i = 0; i < weights.size(); i++) {
		high += weights[i];
	}
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid, weights, days) == true) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>weights(n);
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}
	int days; cin >> days;
	cout << shipWithinDays(weights, days) << endl;
}