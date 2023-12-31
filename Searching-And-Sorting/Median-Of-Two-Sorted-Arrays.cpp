#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/median-of-two-sorted-arrays/

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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size(), n2 = nums2.size();
	//Check to perform binary search on smaller array - to reduce time complexity
	//We will check on smaller array how many elements we have to take on left and right half
	if (n1 > n2) {
		return findMedianSortedArrays(nums2, nums1);
	}
	int low = 0, high = n1;
	int total = (n1 + n2 + 1) / 2;
	while (low <= high) {
		int mid1 = (low + high) / 2;
		int mid2 = total - mid1;
		int l1 = -1e9, l2 = -1e9;
		int r1 = 1e9, r2 = 1e9;
		if (mid1 < n1)r1 = nums1[mid1];
		if (mid2 < n2)r2 = nums2[mid2];
		if (mid1 - 1 >= 0)l1 = nums1[mid1 - 1];
		if (mid2 - 1 >= 0)l2 = nums2[mid2 - 1];

		if (l1 <= r2 && l2 <= r1) {
			if ((n1 + n2) % 2 == 1) {
				//Total Elements are odd
				return max(l1, l2);
			}
			else {
				return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
			}
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
	vector<int>nums1(n);
	for (int i = 0; i < n; i++) {
		cin >> nums1[i];
	}
	int m; cin >> m;
	vector<int>nums2(m);
	for (int i = 0; i < m; i++) {
		cin >> nums2[i];
	}
	cout << findMedianSortedArrays(nums1, nums2) << endl;
}