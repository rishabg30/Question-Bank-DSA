#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/subarrays-with-k-different-integers/

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
int countSubarraysWithAtMostKDistinct(vector<int>&arr, int k) {
	int n = arr.size();
	unordered_map<int, int>mp;

	int si = 0, ei = 0, count = 0;
	while (ei < n) {
		mp[arr[ei]]++;
		ei++;

		while (mp.size() > k) {
			mp[arr[si]]--;
			if (mp[arr[si]] == 0) {
				mp.erase(arr[si]);
			}
			si++;
		}
		count = count + (ei - si);
	}
	return count;
}
int subarraysWithKDistinct(vector<int>& arr, int k) {
	return countSubarraysWithAtMostKDistinct(arr, k) - countSubarraysWithAtMostKDistinct(arr, k - 1);
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
	cout << subarraysWithKDistinct(arr, k) << endl;
}