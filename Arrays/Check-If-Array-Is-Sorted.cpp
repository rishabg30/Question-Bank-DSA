#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int isSorted(int n, vector<int> arr) {
	bool flag = true;
	for (int i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) {
			continue;
		}
		else {
			flag = false;
			break;
		}
	}
	return flag == true;
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
	cout << isSorted(n, arr) << endl;
}