#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/move-zeroes/description/

void printarr(vector<int>&arr) {
	for (auto it : arr) {
		cout << it << " ";
	}
}

void moveZeroes(vector<int>& arr) {
	int i = 0, j = 0;

	int n = arr.size();
	while (j < n) {
		if (arr[j] == 0) {
			j++;
		}
		else {
			swap(arr[i], arr[j]);
			i++;
			j++;
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
	moveZeroes(arr);
	printarr(arr);
}