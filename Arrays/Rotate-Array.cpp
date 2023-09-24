#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/rotate-array/

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
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	k = k % n;
	k = n - k; //To rotate it to the right side

	reverse_arr(nums, 0, k - 1);
	reverse_arr(nums, k, n - 1);
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
	int k; cin >> k;
	rotate(arr, k);
	printarr(arr);
}