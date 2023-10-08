#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/median-of-a-row-wise-sorted-matrix_1115473?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int countSmallerElements(vector<int>&arr, int x, int n) {
	int low = 0, high = n - 1;
	int ans = n;

	while (low <= high) {
		int mid = (low + high) / 2;
		//Can be my potential answer
		//But find something smaller index if found
		if (arr[mid] > x) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

int check(vector<vector<int>> &matrix, int mid) {
	int n = matrix.size(), m = matrix[0].size();
	int count = 0;

	for (int i = 0; i < n; i++) {
		count += countSmallerElements(matrix[i], mid, m);
	}
	return count;
}
int median(vector<vector<int>> &matrix, int m, int n) {
	int low = INT_MAX, high = INT_MIN;
	n = matrix.size(), m = matrix[0].size();
	for (int i = 0; i < n; i++) {
		low = min(low, matrix[i][0]);
		high = max(high, matrix[i][m - 1]);
	}

	int req = (n * m) / 2, ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		int smallerEqual = check(matrix, mid);
		if (smallerEqual <= req) {
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
	int n, m; cin >> n >> m;
	vector<vector<int>>matrix(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << median(matrix, n, m) << endl;
}