#include <bits/stdc++.h>
using namespace std;

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

int findMaximum1s(vector<int>&arr) {
	//Here we can flip at most 1 [0] to make it 1 and we want to find length of maximum
	//subarray consisting of 1s only

	//This question is same as maximum length of subarray consisting of atmost 1 [0]

	int n = arr.size(), si = 0, ei = 0, length = 0, count = 0;
	while (ei < n) {
		if (arr[ei] == 0) {
			count++;
		}
		ei++;

		while (count >= 2) {
			if (arr[si] == 0) {
				count--;
			}
			si++;
		}
		length = max(length, ei - si);
	}
	return length;
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
	cout << findMaximum1s(arr) << endl;
}