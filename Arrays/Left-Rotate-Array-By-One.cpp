#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void printarr(vector<int>&arr) {
	for (auto it : arr) {
		cout << it << " ";
	}
}
void reverse_arr(vector<int>& arr, int si, int ei) {
	while (si <= ei) {
		swap(arr[si], arr[ei]);
		si++;
		ei--;
	}
}
void rotate(vector<int>& nums) {
	int n = nums.size();
	int si = 0, ei = si + 1;

	reverse_arr(nums, si, ei - 1);
	reverse_arr(nums, ei, n - 1);
	reverse_arr(nums, 0, n - 1);
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
	rotate(arr);
	printarr(arr);
}