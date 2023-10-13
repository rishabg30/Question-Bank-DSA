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

int maximumMeetings(vector<int> &start, vector<int> &end) {

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