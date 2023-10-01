#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/subarray-sum-equals-k/

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

int subarraySum(vector<int>& arr, int k) {
	int n = arr.size();

	map<int, int>mp;
	int prefix_sum = 0, count = 0, j = 0;

	for (int i = 0; i < n; i++) {
		prefix_sum += arr[i];
		if (prefix_sum == k) {
			count++;
		}
		if (mp.find(prefix_sum - k) != mp.end()) {
			count += mp[prefix_sum - k];
		}
		mp[prefix_sum]++;
	}
	return count;
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
	int k; cin >> k;
	cout << subarraySum(arr, k) << endl;
}