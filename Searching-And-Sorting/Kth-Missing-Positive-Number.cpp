#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/kth-missing-positive-number/

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

int findKthPositive(vector<int>& arr, int k) {
	int n = arr.size();
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		int missing = arr[mid] - (mid + 1);
		if (missing < k) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return high + 1 + k;
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
	cout << findKthPositive(arr, k) << endl;
}