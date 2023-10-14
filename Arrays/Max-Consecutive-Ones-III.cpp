#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/max-consecutive-ones-iii/

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
//In this question we are asked to find longest subarray consisting of 1 in which
//we can flip at most k zeros

//This question boils down to longest subarray consisting of atmost k zeros
int longestOnes(vector<int>& arr, int k) {
	int n = arr.size(), si = 0, ei = 0, count = 0, length = 0;

	while (ei < n) {
		if (arr[ei] == 0) {
			count++;
		}
		ei++;

		while (count > k) {
			if (arr[si] == 0) {
				count--;
			}
			si++;
		}
		length = max(length, ei - si);
	}
	return length;
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
	cout << longestOnes(arr, k) << endl;
}