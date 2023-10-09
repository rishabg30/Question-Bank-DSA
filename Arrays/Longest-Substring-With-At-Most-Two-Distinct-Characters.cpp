#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/longest-substring-with-at-most-two-distinct-characters_3125863

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
	int n = s.size(), count = 0, length = 0, si = 0, ei = 0;
	vector<int>freq(128, 0);

	while (ei < n) {
		if (count <= 2) {
			if (freq[s[ei]] == 0) {
				count++;
			}
			freq[s[ei]]++;
		}
		ei++;

		while (count > 2) {
			freq[s[si]]--;
			if (freq[s[si]] == 0) {
				count--;
			}
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