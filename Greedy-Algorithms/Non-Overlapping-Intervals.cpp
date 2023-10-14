#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/non-overlapping-intervals/

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

static bool cmp(vector<int>& a, vector<int>& b) {
	return a[1] < b[1];
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	int n = intervals.size();
	//Sorted in increasing order of their end interval
	sort(intervals.begin(), intervals.end(), cmp);

	int count = 1;
	int start = intervals[0][0], end = intervals[0][1];

	for (int i = 1; i < n; i++) {
		if (intervals[i][0] >= end) {
			count++;
			end = intervals[i][1];
		}
	}
	return n - count;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<vector<int>>intervals(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> intervals[i][j];
		}
	}
	cout << eraseOverlapIntervals(intervals) << endl;
}