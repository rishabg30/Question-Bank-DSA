#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/sliding-window-maximum/description/

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
//M1 - Using Priority queue
/*
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
	int n = arr.size(), ei = 0;
	vector<int>ans;
	priority_queue<pair<int, int>>pq;

	while (ei < n) {

		while (pq.size() != 0 && pq.top().second <= ei - k) {
			pq.pop();
		}
		pq.push(make_pair(arr[ei], ei));
		ei++;

		if (ei - k >= 0) {
			ans.push_back(pq.top().first);
		}
	}
	return ans;
}
*/

//M2- Using Deque
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
	int n = arr.size(), ei = 0;
	deque<int>dq;
	vector<int>ans;

	while (ei < n) {
		//Out of window
		while (dq.size() != 0 && dq.front() <= ei - k) {
			dq.pop_front();
		}
		while (dq.size() != 0 && arr[dq.back()] <= arr[ei]) {
			dq.pop_back();
		}
		dq.push_back(ei);
		if (ei >= k - 1) {
			ans.push_back(arr[dq.front()]);
		}
		ei++;
	}
	return ans;
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
	vector<int>ans = maxSlidingWindow(arr, k);
	printArray_1D(ans);
}