#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/reverse-pairs/

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

int merge(vector<int>&arr, int si, int mid, int ei) {
	int j = mid + 1, count = 0;
	for (int i = si; i <= mid; i++) {
		while (j <= ei && arr[i] > 2 * (long long)arr[j]) {
			j++;
		}
		count += (j - (mid + 1));
	}
	vector<int>temp;
	int left = si, right = mid + 1;
	while (left <= mid && right <= ei) {
		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		}
		else {
			temp.push_back(arr[right]);
			right++;
		}
	}
	while (left <= mid) {
		temp.push_back(arr[left]);
		left++;
	}
	while (right <= ei) {
		temp.push_back(arr[right]);
		right++;
	}
	for (int i = si; i <= ei; i++) {
		arr[i] = temp[i - si];
	}
	return count;
}
int my_reversedPairs(vector<int>&arr, int si, int ei) {

	if (si >= ei) {
		return 0;
	}
	int mid = (si + ei) / 2;
	int count = my_reversedPairs(arr, si, mid);
	count += my_reversedPairs(arr, mid + 1, ei);
	count += merge(arr, si, mid, ei);
	return count;
}
int reversePairs(vector<int>& arr) {
	int n = arr.size();
	return my_reversedPairs(arr, 0, n - 1);
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
	cout << reversePairs(arr) << endl;
}