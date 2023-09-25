#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void printarr(vector<int>&arr) {
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << endl;
}
vector<int>sortedArray(vector<int>&arr1, vector<int>&arr2) {
	int n = arr1.size(), m = arr2.size();
	vector<int>my_sorted_array;
	int i = 0, j = 0;

	while (i < n && j < m) {
		if (arr1[i] < arr2[j]) {
			int val = arr1[i];
			i++;
			while (i < n && arr1[i] == val) {
				i++;
			}
			my_sorted_array.push_back(val);
		}
		else if (arr1[i] > arr2[j]) {
			int val = arr2[j];
			j++;
			while (j < m && arr2[j] == val) {
				j++;
			}
			my_sorted_array.push_back(val);
		}
		else {
			int val = arr1[i];
			i++, j++;
			while (i < n && arr1[i] == val) {
				i++;
			}
			while (j < m && arr2[j] == val) {
				j++;
			}
			my_sorted_array.push_back(val);
		}
	}
	while (i < n) {
		int val = arr1[i];
		i++;
		while (i < n && arr1[i] == val) {
			i++;
		}
		my_sorted_array.push_back(val);
	}
	while (j < m) {
		int val = arr2[j];
		j++;
		while (j < m && arr2[j] == val) {
			j++;
		}
		my_sorted_array.push_back(val);
	}
	return my_sorted_array;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m; cin >> n >> m;
	vector<int>arr1(n);
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	vector<int>arr2(m);
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	vector<int>ans = sortedArray(arr1, arr2);
	printarr(ans);
}