#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

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

int maxVowels(string s, int k) {
	if (k > s.size())return -1;

	map<char, int>mp;
	mp.insert({'a', 1});
	mp.insert({'e', 1});
	mp.insert({'i', 1});
	mp.insert({'o', 1});
	mp.insert({'u', 1});

	int n = s.size(), si = 0, ei = 0, length = 0, count = 0, max_count = 0;
	while (ei < n) {
		if (mp.find(s[ei]) != mp.end()) {
			count++;
		}
		length++;
		ei++;

		while (length > k) {
			if (mp.find(s[si]) != mp.end()) {
				count--;
			}
			length--;
			si++;
		}
		max_count = max(max_count, count);
	}
	return max_count;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s; cin >> s;
	int k; cin >> k;
	cout << maxVowels(s, k) << endl;
}