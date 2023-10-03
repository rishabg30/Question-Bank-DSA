#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/longest-subarray-with-zero-sum_6783450?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int getLongestZeroSumSubarrayLength(vector<int> &arr) {
	int n = arr.size();
	int prefix_sum = 0, max_length = 0;

	map<int, int>mp;
	mp[0] = -1;
	for (int i = 0; i < arr.size(); i++) {
		prefix_sum += arr[i];
		if (prefix_sum == 0) {
			max_length = max(max_length, i + 1);
		}

		if (mp.find(prefix_sum) != mp.end()) {
			int prev_index = mp[prefix_sum];
			int curr_index = i;
			max_length = max(max_length, curr_index - prev_index);
		}
		else {
			mp.insert({prefix_sum, i});
		}
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
	cout << getLongestZeroSumSubarrayLength(arr) << endl;
}