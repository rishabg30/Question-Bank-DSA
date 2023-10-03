#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int subarraysWithXorK(vector<int>&arr, int k) {
	int n = arr.size(), count = 0;
	int prefix_xor = 0;

	unordered_map<int, int>mp;
	mp[0] = 1;
	for (int i = 0; i < n; i++) {
		prefix_xor ^= arr[i];

		int x = prefix_xor ^ k;
		count += mp[x];
		mp[prefix_xor]++;
	}
	return count;
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
	int k; cin >> k;
	cout << subarraysWithXorK(arr, k);
}