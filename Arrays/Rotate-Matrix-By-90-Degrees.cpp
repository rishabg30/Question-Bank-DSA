#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/rotate-image/

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

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size(), m = matrix[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	for (int i = 0; i < n; i++) {
		reverse(matrix[i].begin(), matrix[i].end());
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<vector<int>>matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	rotate(matrix);
	printArray_2D(matrix);
}


