#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/sort-colors/

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

void sortColors(vector<int>& arr) {
	int n = arr.size();
	int low = 0, mid = 0, high = n - 1;

	while (mid <= high) {
		if (arr[mid] == 0) {
			swap(arr[low], arr[mid]);
			low++, mid++;
		}
		else if (arr[mid] == 1) {
			mid++;
		}
		else if (arr[mid] == 2) {
			swap(arr[mid], arr[high]);
			high--;
		}
	}
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
	sortColors(arr);
	printArray_1D(arr);
}