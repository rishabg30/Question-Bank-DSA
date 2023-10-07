#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/split-array-largest-sum/

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

int check(int mid, vector<int>&arr, int k) {
	int count = 1, curr_sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (curr_sum + arr[i] <= mid) {
			curr_sum += arr[i];
		}
		//Form a new subarray
		else {
			count++;
			curr_sum = arr[i];
		}
	}
	return count;
}
int splitArray(vector<int>& arr, int k) {
	int n = arr.size();
	int low = *max_element(arr.begin(), arr.end());
	int high = 0, ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		high += arr[i];
	}
	//Search space[max_element_of_array......sum_of_elements_of_array]
	while (low <= high) {
		int mid = (low + high) / 2;
		int subarrays_formed = check(mid, arr, k);
		if (subarrays_formed > k) {
			low = mid + 1;
		}
		else {
			ans = mid;
			high = mid - 1;
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
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int k; cin >> k;
	cout << splitArray(arr, k) << endl;
}