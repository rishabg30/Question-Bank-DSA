#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/binary-search/

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

int search(vector<int>& arr, int target) {
	int low = 0, high = arr.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] < target) {
			low = mid + 1;
		}
		else {
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
	int target; cin >> target;
	cout << search(arr, target);
}