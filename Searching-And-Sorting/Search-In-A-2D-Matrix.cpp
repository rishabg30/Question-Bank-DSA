#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/search-a-2d-matrix/

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

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int n = matrix.size(), m = matrix[0].size();

	int low = 0, high = (n * m) - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		int r = mid / m, c = mid % m;
		if (matrix[r][c] == target)return true;

		else if (matrix[r][c] < target) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
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
	int n, m; cin >> n >> m;
	vector<vector<int>>matrix(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	int target; cin >> target;
	cout << searchMatrix(matrix, target) << endl;
}