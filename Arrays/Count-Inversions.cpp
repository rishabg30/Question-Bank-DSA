#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/number-of-inversions_6840276?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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
	vector<int>temp;
	int count = 0;
	int left = si, right = mid + 1;

	while (left <= mid && right <= ei) {
		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		}
		else {
			temp.push_back(arr[right]);
			count += (mid - left + 1);
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
int countInversions(vector<int>&arr, int si, int ei) {

	if (si >= ei) {
		return 0;
	}
	int count = 0;
	int mid = (si + ei) / 2;
	count += countInversions(arr, si, mid);
	count += countInversions(arr, mid + 1, ei);
	count += merge(arr, si, mid, ei);
	return count;
}
int numberOfInversions(vector<int>&arr, int n) {
	return countInversions(arr, 0, n - 1);
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
	cout << numberOfInversions(arr, n) << endl;
}