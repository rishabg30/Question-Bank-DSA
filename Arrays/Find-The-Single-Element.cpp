#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/single-number/

int singleNumber(vector<int>& nums) {
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		ans = ans ^ nums[i];
	}
	return ans;
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
	cout << singleNumber(nums) << endl;
}