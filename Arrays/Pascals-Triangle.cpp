#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/pascals-triangle/

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

vector<vector<int>> generate(int n) {
	vector<vector<int>>ans(n);
	for (int i = 0; i < n; i++) {
		ans[i].resize(i + 1);
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				ans[i][j] = 1;
			}
			else {
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
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
	int n; cin >> n;
	vector<vector<int>>ans = generate(n);
	printArray_2D(ans);
}