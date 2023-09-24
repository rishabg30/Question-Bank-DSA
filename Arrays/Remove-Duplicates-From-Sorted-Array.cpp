#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/remove-duplicates-from-sorted-array_1102307?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int removeDuplicates(vector<int> &arr, int n) {
	int k = 1;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] != arr[i - 1]) {
			arr[k] = arr[i];
			k++;
		}
	}
	return k;
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
	cout << removeDuplicates(arr, n) << endl;
}