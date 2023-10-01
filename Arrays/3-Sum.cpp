#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/3sum/

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

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>>ans;

	for (int i = 0; i < nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		int j = i + 1, k = nums.size() - 1;
		while (j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			if (sum < 0) {
				j++;
			}
			else if (sum > 0) {
				k--;
			}
			else {
				vector<int>triplet{nums[i], nums[j], nums[k]};
				ans.push_back(triplet);
				j++;
				k--;
				while (j < k && nums[j] == nums[j - 1]) {
					j++;
				}
				while (j < k && nums[k] == nums[k + 1]) {
					k--;
				}
			}
		}
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
	vector<vector<int>>ans = threeSum(nums);
	printArray_2D(ans);
}