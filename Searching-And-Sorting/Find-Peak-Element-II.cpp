#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-a-peak-element-ii/description/

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

int findMaxIndex(vector<vector<int>>& matrix, int n, int m, int mid) {
	int maxValue = -1, index = -1;
	for (int i = 0; i < n; i++) {
		if (matrix[i][mid] > maxValue) {
			maxValue = matrix[i][mid];
			index = i;
		}
	}
	return index;
}
vector<int> findPeakGrid(vector<vector<int>>& matrix) {
	int n = matrix.size(), m = matrix[0].size();
	int low = 0, high = m - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		int maxRowIndex = findMaxIndex(matrix, n, m, mid);
		int left_element = (mid - 1 >= 0) ? matrix[maxRowIndex][mid - 1] : -1;
		int right_element = (mid + 1 < m) ? matrix[maxRowIndex][mid + 1] : -1;
		//If this element is greater than it's left and right then its a peak element
		if (matrix[maxRowIndex][mid] > left_element && matrix[maxRowIndex][mid] > right_element) {
			return {maxRowIndex, mid};
		}
		else if (matrix[maxRowIndex][mid] < left_element) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return { -1, -1};
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
	vector<int>ans = findPeakGrid(matrix);
	printArray_1D(ans);
}