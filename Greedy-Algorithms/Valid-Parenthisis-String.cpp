#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/valid-parenthesis-string/description/

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
bool checkValidString(string s) {

}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s; cin >> s;
	cout << checkValidString(s) << endl;
}