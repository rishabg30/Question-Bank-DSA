#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/two-sum/

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

vector<int> twoSum(vector<int>& arr, int target) {
	map<int, int>mp;
	for (int i = 0; i < arr.size(); i++) {
		if (mp.find(target - arr[i]) != mp.end()) {
			return {mp[target - arr[i]], i};
		}
		else {
			mp.insert({arr[i], i});
		}
	}
	return {};
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
	int target; cin >> target;
	vector<int>ans = twoSum(arr, target);
	printArray_1D(ans);
}