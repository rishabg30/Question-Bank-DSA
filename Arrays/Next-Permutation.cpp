#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/next-permutation/

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
void nextPermutation(vector<int>& arr) {
	int n = arr.size();
	if (n <= 1) {
		return;
	}

	int idx1 = -1;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1]) {
			idx1 = i;
			break;
		}
	}

	if (idx1 == -1) {
		reverse(arr.begin(), arr.end());
		return;
	}

	int idx2 = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] > arr[idx1]) {
			idx2 = i;
			break;
		}
	}
	swap(arr[idx1], arr[idx2]);
	reverse(arr.begin() + idx1 + 1, arr.end());
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
	nextPermutation(arr);
	printArray_1D(arr);
}