#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/max-consecutive-ones/

int findMaxConsecutiveOnes(vector<int>& nums) {
	int count = 0, max_count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			count++;
		}
		else {
			count = 0;
		}
		max_count = max(max_count, count);
	}
	return max_count;
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
	cout << findMaxConsecutiveOnes(nums) << endl;
}