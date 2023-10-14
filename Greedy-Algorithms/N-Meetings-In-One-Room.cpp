#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

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

//Approach - Attend the meetings whose end time is minimum
int maximumMeetings(vector<int> &start, vector<int> &end) {
	int n = start.size();
	vector<vector<int>>meetings;
	for (int i = 0; i < n; i++) {
		vector<int>curr = {end[i], start[i]};
		meetings.push_back(curr);
	}
	sort(meetings.begin(), meetings.end());
	int count = 0, prev_end = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (meetings[i][1] > prev_end) {
			count++;
			prev_end = meetings[i][0];
		}
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
	vector<int>start(n);
	for (int i = 0; i < n; i++) {
		cin >> start[i];
	}
	vector<int>end(n);
	for (int i = 0; i < n; i++) {
		cin >> end[i];
	}
	cout << maximumMeetings(start, end) << endl;
}