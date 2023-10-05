#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

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

bool search(vector<int>& arr, int target) {

	int low = 0, high = arr.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == target)return true;

		//If duplicates are present in the array
		if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
			low++;
			high--;
			continue;
		}

		//Check which region is sorted
		if (arr[low] <= arr[mid]) {
			//Left area is sorted
			if (arr[low] <= target && target <= arr[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		else {
			//Right area is sorted
			if (arr[mid] <= target && target <= arr[high]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
	}
	return false;
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
	cout << search(arr, target) << endl;
}