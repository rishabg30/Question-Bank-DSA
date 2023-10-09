#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-window-substring/

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

string minWindow(string s, string t) {
	int ns = s.size(), nt = t.size();
	vector<int>freq(128, 0);

	for (int i = 0; i < t.size(); i++) {
		freq[t[i]]++;
	}
	int si = 0, ei = 0, count = nt, length = 1e9, gsi = 0;
	while (ei < ns) {
		if (freq[s[ei]] > 0) {
			count--;
		}
		freq[s[ei]]--;
		ei++;

		while (count == 0) {
			if (ei - si < length) {
				length = ei - si;
				gsi = si;
			}
			if (freq[s[si]] == 0) {
				count++;
			}
			freq[s[si]]++;
			si++;
		}
	}
	return (length == 1e9) ? "" : s.substr(gsi, length);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s, t; cin >> s >> t;
	cout << minWindow(s, t) << endl;
}