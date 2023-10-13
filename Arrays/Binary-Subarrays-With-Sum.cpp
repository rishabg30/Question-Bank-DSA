#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/binary-subarrays-with-sum/description/

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

int countSubarraysWithSumAtmostGoal(vector<int>&arr, int k) {
	int n = arr.size(), curr_sum = 0, si = 0, ei = 0, count = 0;

	while (ei < n) {
		curr_sum += arr[ei];
		ei++;

		while (curr_sum > k) {
			curr_sum -= arr[si];
			si++;
		}
		count += (ei - si);
	}
	return count;
}
int numSubarraysWithSum(vector<int>& arr, int goal) {
	int x = countSubarraysWithSumAtmostGoal(arr, goal);
	if (goal > 0) {
		int y = countSubarraysWithSumAtmostGoal(arr, goal - 1);
		return x - y;
	}
	return x;
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
	int goal; cin >> goal;
	cout << numSubarraysWithSum(arr, goal);
}