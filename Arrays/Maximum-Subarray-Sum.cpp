#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-subarray/description/

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
int maxSubArray(vector<int>& arr) {
	int n = arr.size();

	int curr_sum = 0, max_sum = -1e9;
	for (int i = 0; i < n; i++) {
		curr_sum += arr[i];
		max_sum = max(max_sum, curr_sum);
		if (curr_sum < 0) {
			curr_sum = 0;
		}
	}
	return max_sum;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << maxSubArray(arr) << endl;
}