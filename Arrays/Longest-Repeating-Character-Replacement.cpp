#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/longest-repeating-character-replacement/

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

int characterReplacement(string s, int k) {
	int n = s.size(), si = 0, ei = 0, length = 0;

	vector<int>freq(26, 0);
	int max_char_count = 0;
	while (ei < n) {
		freq[s[ei] - 'A']++;
		max_char_count = max(max_char_count, freq[s[ei] - 'A']);
		ei++;

		while (ei - si - max_char_count > k) {
			freq[s[si] - 'A']--;
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
	int k; cin >> k;
	cout << characterReplacement(s, k) << endl;
}