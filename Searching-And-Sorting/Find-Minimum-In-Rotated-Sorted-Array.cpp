#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

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

int findMin(vector<int>& arr) {

	int low = 0, high = arr.size() - 1;
	int minAns = INT_MAX;
	while (low <= high) {
		int mid = (low + high) / 2;

		//Check which region is sorted
		if (arr[low] <= arr[mid]) {
			//Left area is sorted
			minAns = min(minAns, arr[low]);
			low = mid + 1;
		}
		else {
			//Right area is sorted
			minAns = min(minAns, arr[mid]);
			high = mid - 1;
		}
	}
	return minAns;
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
	cout << findMin(arr) << endl;
}