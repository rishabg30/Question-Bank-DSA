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
int longestSubarrayWithSumK(vector<int> arr, long long k) {
	long long sum = 0, i = 0, j = 0, max_length = 0;

	int n = arr.size();
	while (i < n) {
		sum = sum + arr[i];
		while (j <= i && sum > k) {
			sum = sum - arr[j];
			j++;
		}
		if (sum == k) {
			max_length = max(max_length, i - j + 1);
		}
		i++;
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
	cout << longestSubarrayWithSumK(arr, k) << endl;
}