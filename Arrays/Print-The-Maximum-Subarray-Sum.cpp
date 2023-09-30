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
void printmaxSubArray(vector<int>& arr) {
	int n = arr.size();
	int si = 0, ei = 0;

	int curr_sum = 0, max_sum = -1e9;
	for (int i = 0; i < n; i++) {
		curr_sum += arr[i];
		if (curr_sum > max_sum) {
			ei = i;
			max_sum = max(max_sum, curr_sum);
		}
		if (curr_sum < 0) {
			curr_sum = 0;
		}
	}

	for (int i = ei; i >= 0; i--) {
		max_sum = max_sum - arr[i];
		if (max_sum == 0) {
			si = i;
			break;
		}
	}

	for (int i = si; i <= ei; i++) {
		cout << arr[i] << " ";
	}
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
	printmaxSubArray(arr);
}