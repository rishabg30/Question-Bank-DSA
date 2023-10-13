#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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

long long int countSubarrWithEqualZeroAndOne(vector<int> arr, int n) {
	long long ei = 0, curr_sum = 0, count = 0;
	unordered_map<int, int>mp;

	mp[0] = 1;
	while (ei < n) {
		if (arr[ei] == 1) {
			curr_sum += 1;
		}
		else {
			curr_sum -= 1;
		}
		ei++;
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
	cout << countSubarrWithEqualZeroAndOne(arr, n) << endl;
}