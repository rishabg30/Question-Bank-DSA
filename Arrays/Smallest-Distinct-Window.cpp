#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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
int findSubString(string s) {
	int ns = s.size(), count = 0;
	vector<int>freq(128, 0);
	for (int i = 0; i < s.size(); i++) {
		if (freq[s[i]] == 0) {
			freq[s[i]]++;
			count++;
		}
	}
	int si = 0, ei = 0, length = 1e9, gsi = 0;
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
	return length;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string str; cin >> str;
	cout << findSubString(str) << endl;
}