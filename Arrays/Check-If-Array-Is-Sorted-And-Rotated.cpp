#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

bool check(vector<int>& arr) {
	int n = arr.size(), count = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			count++;
		}
	}

	if (arr[n - 1] > arr[0]) {
		count++;
	}
	return count <= 1;
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
	cout << check(arr);
}