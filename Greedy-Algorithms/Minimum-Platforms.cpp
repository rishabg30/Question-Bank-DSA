#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

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
int findPlatform(vector<int>arrival, vector<int>departure, int n) {

}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>arrival(n), departure(n);
	for (int i = 0; i < n; i++) {
		cin >> arrival[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> departure[i];
	}
	cout << findPlatform(arrival, departure, n);
}