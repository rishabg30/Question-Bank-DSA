#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

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

int lengthOfLongestSubstring(string s) {
	if (s.size() <= 0)return 0;

	int n = s.size(), si = 0, ei = 0, length = 0, count = 0;
	vector<int>freq(128, 0);

	while (ei < n) {
		if (freq[s[ei]] > 0) {
			count++;
		}
		freq[s[ei]]++;
		ei++;

		while (count > 0) {
			if (freq[s[si]] > 1) {
				count--;
			}
			freq[s[si]]--;
			si++;
		}
		length = max(length, ei - si);
	}
	return length;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s; cin >> s;
	cout << lengthOfLongestSubstring(s) << endl;
}