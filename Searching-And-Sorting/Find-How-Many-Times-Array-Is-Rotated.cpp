#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/rotation_7449070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int findKRotation(vector<int> &arr) {
	//Just find the minimum in rotated sorted array and the index at which is present will
	//be the number of times array has been rotated

	int low = 0, high = arr.size() - 1;
	int minAns = INT_MAX, index = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		//Check which region is sorted
		if (arr[low] <= arr[mid]) {
			if (arr[low] < minAns) {
				minAns = arr[low];
				index = low;
			}
			low = mid + 1;
		}
		else {
			if (arr[mid] < minAns) {
				minAns = arr[mid];
				index = mid;
			}
			high = mid - 1;
		}
	}
	return index;
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
	cout << findKRotation(arr) << endl;
}