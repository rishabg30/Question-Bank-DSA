#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/spiral-matrix/

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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int n = matrix.size(), m = matrix[0].size();
	int up = 0, right = m - 1, down = n - 1, left = 0;
	vector<int>ans;

	int dir = 0;
	while (true) {
		if (dir == 0) {
			//Upper row
			int i = left, j = right;
			while (i <= j) {
				ans.push_back(matrix[up][i]);
				i++;
			}
			up++;
			dir++;
		}

		else if (dir == 1) {
			//Right column
			int i = up, j = down;
			while (i <= j) {
				ans.push_back(matrix[i][right]);
				i++;
			}
			right--;
			dir++;
		}

		else if (dir == 2) {
			//Bottom row (reverse order)
			int i = right, j = left;
			while (i >= j) {
				ans.push_back(matrix[down][i]);
				i--;
			}
			down--;
			dir++;
		}

		else if (dir == 3) {
			//Left column (reverse order)
			int i = down, j = up;
			while (i >= j) {
				ans.push_back(matrix[i][left]);
				i--;
			}
			left++;
			dir++;
		}
		dir = dir % 4;
		if (ans.size() == n * m) {
			break;
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
	vector<int>ans = spiralOrder(matrix);
	printArray_1D(ans);
}