#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/longest-consecutive-sequence/description/

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

int longestConsecutive(vector<int>& arr) {
	int n = arr.size();
	unordered_set<int>st;
	for (int i = 0; i < n; i++) {
		st.insert(arr[i]);
	}

	int max_len = 0, count = 0;
	for (int i = 0; i < n; i++) {
		if (st.find(arr[i] - 1) != st.end()) {
			continue;
		}
		else {
			count = 1;
			while (true) {
				if (st.find(arr[i] + count) != st.end()) {
					count++;
				}
				else {
					break;
				}
			}
		}
		max_len = max(max_len, count);
	}
	return max_len;
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
	cout << longestConsecutive(arr) << endl;
}