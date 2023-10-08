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

	int x = 0, y = m - 1;
	while (x >= 0 && y >= 0 && x < n && y < m) {
		if (matrix[x][y] == target) {
			return true;
		}
		else if (matrix[x][y] < target) {
			x++;
		}
		else {
			y--;
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