#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse

int largestElement(vector<int> &arr, int n) {
	int maxElement = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		maxElement = max(maxElement, arr[i]);
	}
	return maxElement;
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
	cout << largestElement(arr, n) << endl;
}