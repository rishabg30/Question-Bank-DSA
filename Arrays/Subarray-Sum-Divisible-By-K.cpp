#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/subarray-sums-divisible-by-k/

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

int subarraysDivByK(vector<int>& arr, int k) {
	int n = arr.size();
	int ei = 0, curr_sum = 0, count = 0;
	unordered_map<int, int>mp;

	mp[0] = 1;
	while (ei < n) {
		curr_sum = (curr_sum + arr[ei]) % k;
		ei++;
		if (curr_sum < 0)curr_sum += k;

		count += mp[curr_sum];
		mp[curr_sum]++;
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
	cout << subarraysDivByK(arr, k) << endl;
}