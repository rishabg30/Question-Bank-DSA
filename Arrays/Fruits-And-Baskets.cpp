#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/fruits-and-baskets_985356?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int findMaxFruits(vector<int> &arr, int n) {
	int max_count = 0, count = 0, j = 0;
	map<int, int>mp;
	for (int i = 0; i < arr.size(); i++) {
		count++;
		mp[arr[i]]++;

		if (mp.size() > 2) {

			while (mp.size() > 2) {
				mp[arr[j]]--;
				count--;
				if (mp[arr[j]] == 0) {
					mp.erase(arr[j]);
				}
				j++;
			}
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
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << findMaxFruits(arr, n) << endl;
}