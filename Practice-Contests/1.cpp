#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<string>&arr) {
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

vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
	vector<string>myans;
	vector<int>arr1(n, 1);
	vector<int>arr2(n, 1);

	vector<vector<int>>ans(n + 2, vector<int>(n + 2));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = 0;
			if (words[i].size() == words[j].size()) {
				for (int k = 0; k < words[i].size(); k++) {
					x = x + (words[i][k] != words[j][k]);
				}
				ans[i][j] = x;
			}
		}
	}
	for (int i = 0; i <= n - 1; i++) {
		arr2[i] = i;
		for (int curr = 0; curr <= i - 1; curr++) {
			if ((groups[curr] != groups[i] && words[i].size() == words[curr].size() && ans[i][curr] == 1)
			        && 1 + arr1[curr] > arr1[i]) {
				arr1[i] = arr1[curr] + 1;
				arr2[i] = curr;
			}
		}
	}
	int x = -1, y = -1;
	for (int i = 0; i <= n - 1; i++) {
		if (arr1[i] > x) {
			x = arr1[i];
			y = i;
		}
	}
	myans.push_back(words[y]);
	while (arr2[y] != y) {
		y = arr2[y];
		myans.push_back(words[y]);
	}
	reverse(myans.begin(), myans.end());
	return myans;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<string>words = {"bad", "dc", "bc", "ccd", "dd", "da", "cad", "dba", "aba"};
	vector<int>groups = {9, 7, 1, 2, 6, 8, 3, 7, 2};
	vector<string>ans = getWordsInLongestSubsequence(9, words, groups);
	printArray_1D(ans);
}