#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/single-element-in-a-sorted-array/

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

int singleNonDuplicate(vector<int>& arr) {
	int n = arr.size();
	if (n == 1) {
		return arr[0];
	}
	//Base cases handled
	if (arr[0] != arr[1])return arr[0];
	if (arr[n - 1] != arr[n - 2])return arr[n - 1];

	int low = 1, high = n - 2;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
			return arr[mid];
		}

		//Left region
		if ((mid % 2 == 1) && (arr[mid] == arr[mid - 1]) ||
		        (mid % 2 == 0) && (arr[mid] == arr[mid + 1])) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
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
	cout << singleNonDuplicate(arr) << endl;
}