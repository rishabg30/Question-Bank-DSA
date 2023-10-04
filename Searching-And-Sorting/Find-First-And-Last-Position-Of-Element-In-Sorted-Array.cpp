#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

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

int startPos(vector<int>&arr, int x) {
	int low = 0, high = arr.size() - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == x) {
			ans = mid;
			high = mid - 1;
		}
		else if (arr[mid] < x) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}
int endPos(vector<int>&arr, int x) {
	int low = 0, high = arr.size() - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == x) {
			ans = mid;
			low = mid + 1;
		}
		else if (arr[mid] < x) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}
vector<int> searchRange(vector<int>& arr, int x) {

	int start_position = startPos(arr, x);
	int end_position = endPos(arr, x);
	return {start_position, end_position};
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
	int x; cin >> x;
	vector<int>ans = searchRange(arr, x);
	printArray_1D(ans);
}