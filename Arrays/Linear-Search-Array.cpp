#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/linear-search_6922070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int linearSearch(int n, int num, vector<int> &arr) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == num) {
			return i;
		}
	}
	return -1;
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
	int num; cin >> num;
	cout << linearSearch(n, num, arr);
}