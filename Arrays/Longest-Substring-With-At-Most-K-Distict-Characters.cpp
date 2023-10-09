#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/longest-substring-with-at-most-k-distinct-characters_2221410?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

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

int kDistinctChars(int k, string &str) {
	if (str.size() <= 0)return 0;

	int n = str.size(), si = 0, ei = 0, count = 0, length = 0;
	vector<int>freq(128, 0);

	while (ei < n) {
		if (freq[str[ei]] == 0) {
			count++;
		}
		freq[str[ei]]++;
		ei++;

		while (count > k) {
			freq[str[si]]--;
			if (freq[str[si]] == 0) {
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
	string str; cin >> str;
	int k; cin >> k;
	cout << kDistinctChars(k, str) << endl;
}