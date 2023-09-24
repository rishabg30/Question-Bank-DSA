#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void printarr(vector<int>&arr) {
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << endl;
}
// vector<int>sortedArray(vector<int>&arr1, vector<int>&arr2) {

// }

int traffic(int n, int m, vector<int> vehicle) {

	int i = 0, max_length = 0;
	while (i < n && m != 0) {
		if (vehicle[i] == 0) {
			m--;
		}
		i++;
		max_length = max(max_length, i);
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << traffic(n, m, arr1);
	// int m; cin >> m;
	// vector<int>arr2(m);
	// for (int i = 0; i < m; i++) {
	// 	cin >> arr2[i];
	// }
	// vector<int>ans = sortedArray(arr1, arr2);
	// printarr(ans);
}