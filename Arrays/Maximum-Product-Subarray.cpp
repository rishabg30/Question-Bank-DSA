#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-product-subarray/

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

int maxProduct(vector<int>& arr) {
	int n = arr.size(), myMax = INT_MIN;
	int prefix = 1, suffix = 1;

	for (int i = 0; i < n; i++) {
		if (prefix == 0) {
			prefix = 1;
		}
		if (suffix == 0) {
			suffix = 1;
		}
		prefix = prefix * arr[i];
		suffix = suffix * arr[n - i - 1];
		myMax = max(myMax, max(prefix, suffix));
	}
	return myMax;
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
	cout << maxProduct(arr) << endl;
}