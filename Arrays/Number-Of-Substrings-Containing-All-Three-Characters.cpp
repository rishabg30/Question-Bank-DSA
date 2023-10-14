#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

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

int numberOfSubstrings(string s) {
	unordered_map<char, int> mp;
	int count = 0, si = 0, ei = 0;
	int n = s.size();

	while (ei < n) {
		mp[s[ei]]++;

		while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
			count += n - ei;
			mp[s[si]]--;
			si++;
		}
		ei++;
	}
	return count;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s; cin >> s;
	cout << numberOfSubstrings(s) << endl;
}