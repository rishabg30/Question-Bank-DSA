#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

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
int getLongestSubarray(vector<int>& arr, int k) {
	int n = arr.size();
	int prefix_sum = 0, max_length = 0;
	map<int, int>mp;

	for (int i = 0; i < n; i++) {
		prefix_sum += arr[i];

		if (prefix_sum == k) {
			max_length = max(max_length, (i + 1));
		}
		if (mp.find(prefix_sum - k) != mp.end()) {
			max_length = max(max_length, i - mp[prefix_sum - k]);
		}
		mp.insert({prefix_sum, i});
	}
	return max_length;
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
	cout << getLongestSubarray(arr, k) << endl;
}