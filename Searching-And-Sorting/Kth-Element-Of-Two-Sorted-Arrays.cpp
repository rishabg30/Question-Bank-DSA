#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/k-th-element-of-2-sorted-array_1164159?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k) {
	//Check to perform binary search on smaller array - to reduce time complexity
	//We will check on smaller array how many elements we have to take on left and right half

	//We are splitting like this : Left - K elements , Right - Remaining (n + m - K) elements
	//Therefore low - max(0, k-m) , high - min(k,n);
	if (n > m) {
		return kthElement(arr2, arr1, m, n, k);
	}
	int low = max(k - m, 0), high = min(k, n);
	int total = k; //How many elements will be on the left
	while (low <= high) {
		int mid1 = (low + high) / 2;
		int mid2 = total - mid1;
		int l1 = -1e9, l2 = -1e9;
		int r1 = 1e9, r2 = 1e9;
		if (mid1 < n)r1 = arr1[mid1];
		if (mid2 < m)r2 = arr2[mid2];
		if (mid1 - 1 >= 0)l1 = arr1[mid1 - 1];
		if (mid2 - 1 >= 0)l2 = arr2[mid2 - 1];

		if (l1 <= r2 && l2 <= r1) {
			return max(l1, l2);
		}
		else if (l1 > r2) {
			high = mid1 - 1;
		}
		else {
			low = mid1 + 1;
		}
	}
	return 0;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>arr1(n);
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	int m; cin >> m;
	vector<int>arr2(m);
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	int k; cin >> k;
	cout << kthElement(arr1, arr2, n, m, k);
}