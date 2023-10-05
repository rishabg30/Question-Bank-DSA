#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-peak-element/description/

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

int findPeakElement(vector<int>& arr) {
	int n = arr.size();
	if (n == 1)return 0;
	if (arr[0] > arr[1])return 0;
	if (arr[n - 1] > arr[n - 2])return n - 1;

	int low = 1, high = n - 2;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
			return mid;
		}
		//Increasing curve: remove the left region
		else if (arr[mid] > arr[mid - 1]) {
			low = mid + 1;
		}
		//Decreasing curve: remove the right region
		else if (arr[mid] > arr[mid + 1]) {
			high = mid - 1;
		}
	}
	return -1;
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
	cout << findPeakElement(arr) << endl;
}