#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

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

bool check(int mid, vector<int>&stalls, int k) {
	k--; //Ensuring first cow to be placed at very first stall
	int prev_position = stalls[0];
	for (int i = 1; i < stalls.size(); i++) {
		if (k == 0)return true;

		int curr_distance = stalls[i] - prev_position;
		if (curr_distance >= mid) {
			k--;
			prev_position = stalls[i];
		}
	}
	return (k == 0);
}
int aggressiveCows(vector<int> &stalls, int k) {
	int low = 0, high = *max_element(stalls.begin(), stalls.end());
	int ans = -1;
	sort(stalls.begin(), stalls.end());

	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid, stalls, k) == true) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
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
	vector<int>stalls(n);
	for (int i = 0; i < n; i++) {
		cin >> stalls[i];
	}
	int k; cin >> k;
	cout << aggressiveCows(stalls, k) << endl;
}