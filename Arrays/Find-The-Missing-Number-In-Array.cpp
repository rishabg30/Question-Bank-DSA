#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/missing-number/description/

int missingNumber(vector<int>& nums) {
	int n = nums.size();
	int actual_sum = 0, curr_sum = 0;

	actual_sum = (n * (n + 1) / 2);
	for (int i = 0; i < n; i++) {
		curr_sum += nums[i];
	}
	return actual_sum - curr_sum;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << missingNumber(nums);
}