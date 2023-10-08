#include <bits/stdc++.h>
using namespace std;

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
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
	int curr_idx = INT_MAX, max_ones = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		int low = 0, high = m - 1, count_ones = 0;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (matrix[i][mid] == 1) {
				curr_idx = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		count_ones = (m - curr_idx);
		if (count_ones > max_ones) {
			max_ones = count_ones;
			ans = i;
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
	cout << rowWithMax1s(matrix, n, m) << endl;
}