#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/merge-intervals/

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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size();
	vector<vector<int>>ans;
	if (n == 0) {
		return ans;
	}
	sort(intervals.begin(), intervals.end());
	pair<int, int>startPair;
	startPair.first = intervals[0][0], startPair.second = intervals[0][1];

	for (int i = 0; i < intervals.size(); i++) {
		vector<int>curr_Interval = intervals[i];
		if (startPair.second >= curr_Interval[0]) {
			//Intervals can be merged
			startPair.first = min(startPair.first, curr_Interval[0]);
			startPair.second = max(startPair.second, curr_Interval[1]);
		}
		else {
			//Intervals can't be merged. Put previous interval into ans and update this interval to be the latest interval
			ans.push_back({startPair.first, startPair.second});
			startPair.first = curr_Interval[0];
			startPair.second = curr_Interval[1];
		}
	}
	ans.push_back({startPair.first, startPair.second});
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

	vector<vector<int>>ans = merge(intervals);
	printArray_2D(ans);
}