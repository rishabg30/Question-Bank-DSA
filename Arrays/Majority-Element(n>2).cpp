#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/majority-element/

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

int majorityElement(vector<int>& arr) {
	int n = arr.size();

	int count = 0, element = 0;
	for (int i = 0; i < n; i++) {
		if (count == 0) {
			element = arr[i];
		}
		if (element == arr[i]) {
			count++;
		}
		else {
			count--;
		}
	}
	return element;
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
	cout << majorityElement(arr) << endl;
}