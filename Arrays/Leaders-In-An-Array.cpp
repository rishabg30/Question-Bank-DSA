#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/superior-elements_6783446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

vector<int> superiorElements(vector<int>&arr) {
	int n = arr.size();
	if (n == 1) {
		return arr;
	}

	vector<int>ans;
	ans.push_back(arr[n - 1]);
	int max = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > max) {
			ans.push_back(arr[i]);
			max = arr[i];
		}
	}
	return ans;
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
	vector<int>ans = superiorElements(arr);
	printArray_1D(ans);
}