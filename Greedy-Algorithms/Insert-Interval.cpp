#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/insert-interval/

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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	int n = intervals.size();
	vector<vector<int>>ans;

	for (auto it : intervals) {
		if (it[1] < newInterval[0]) {
			ans.push_back(it);
		}
		else if (it[0] > newInterval[1]) {
			ans.push_back(newInterval);
			newInterval = it;
		}
		//Merge the intervals
		else {
			newInterval[0] = min(newInterval[0], it[0]);
			newInterval[1] = max(newInterval[1], it[1]);
		}
	}
	ans.push_back(newInterval);
	return ans;
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
	vector<int>newInterval(2);
	for (int i = 0; i < 2; i++) {
		cin >> newInterval[i];
	}

	vector<vector<int>>ans = insert(intervals, newInterval);
	printArray_2D(ans);
}