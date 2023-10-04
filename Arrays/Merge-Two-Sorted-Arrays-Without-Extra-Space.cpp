#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/merge-sorted-array/

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

void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	int gap = (gap / 2) + (gap % 2);
	while (gap > 0) {
		int leftptr = 0, rightptr = leftptr + gap;
		while (rightptr < (n + m)) {
			//leftptr - arr1
			//rightptr - arr2
			if (leftptr < n && rightptr >= n) {
				if (arr1[leftptr] > arr2[n - rightptr]) {
					swap(arr1[leftptr], arr2[n - rightptr]);
				}
			}
			//leftptr - arr2
			//rightptr - arr2
			else if (leftptr >= n && rightptr >= n) {
				if (arr2[leftptr - n] > arr2[rightptr - n]) {
					swap(arr2[leftptr - n], arr2[rightptr - n]);
				}
			}
			//leftptr - arr1
			//rightptr - arr1
			else {
				if (arr1[leftptr] > arr2[rightptr]) {
					swap(arr1[leftptr], arr2[rightptr]);
				}
			}
			leftptr++;
			rightptr++;
		}
		if (gap == 1)break;
		gap = (gap / 2) + (gap % 2);
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>arr1(n);
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	int m; cin >> m;
	vector<int>arr2(m);
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	merge(arr1, n, arr2, m);
	printArray_1D(arr1);
	printArray_1D(arr2);
}