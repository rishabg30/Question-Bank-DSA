#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

void printarr(vector<int>&arr) {
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << endl;
}
void merge_sortedArray(vector<int>&arr1, vector<int>&arr2) {

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
	merge_sortedArray(arr1, arr2);
	printarr(arr1);
	printarr(arr2);
}