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