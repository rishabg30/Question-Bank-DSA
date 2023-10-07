#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/assign-cookies_8390826?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int n = g.size() , m = s.size();

	int i = 0, j = 0, count = 0;
	while (i < n && j < m) {
		if (g[i] <= s[j]) {
			//Can give candy
			count++;
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	return count;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>g(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	int m; cin >> m;
	vector<int>s(m);
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	cout << findContentChildren(g, s) << endl;
}