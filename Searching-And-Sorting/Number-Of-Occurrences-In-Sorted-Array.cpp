#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int count(vector<int>& arr, int n, int x) {
	auto si = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	auto ei = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

	return ei - si;
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
	cout << count(arr, n, x) << endl;
}