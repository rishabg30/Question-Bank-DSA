#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/contiguous-array/description/
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

int findMaxLength(vector<int>& arr) {
	int n = arr.size(), ei = 0, curr_sum = 0, length = 0, max_length = 0;
	unordered_map<int, pair<int, int>>mp;

	mp[0] = make_pair(1, 0);
	while (ei < n) {
		if (arr[ei] == 1) {
			curr_sum += 1;
		}
		else {
			curr_sum -= 1;
		}
		ei++;
		if (mp.find(curr_sum) == mp.end()) {
			mp[curr_sum] = make_pair(1, ei);
		}
		else {
			pair<int, int>p = mp[curr_sum];
			p.first++;
			mp[curr_sum] = p;

			length = ei - p.second;
		}
		max_length = max(max_length, length);
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
	cout << findMaxLength(arr) << endl;
}