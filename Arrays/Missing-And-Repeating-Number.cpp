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

vector<int> findMissingRepeatingNumbers(vector<int>&arr) {
	int n = arr.size();
	int XOR = 0;
	for (int i = 0; i < n; i++) {
		XOR ^= arr[i];
		XOR ^= (i + 1);
	}
	// Calculating the differ bit in the number
	int temp = XOR, count = 0;
	while (temp) {
		if ((temp & (1 << count)) != 0) {
			break;
		}
		else {
			count++;
		}
	}
	// Segregate them into two sets
	// 1st Set - elements containing their first bit as 1
	// 2nd Set - elements containing their first bit as 0
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		int mask = (1 << count);
		if ((arr[i] & mask) != 0) {
			x ^= arr[i];
		}
		else {
			y ^= arr[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		int mask = (1 << count);
		if ((i & mask) != 0) {
			x ^= i;
		}
		else {
			y ^= i;
		}
	}

// Now we have x and y which are our repeating and missing number
// To identify which one is whom iterate again in array and check the occurence.
	int repeating_number = 0, missing_number = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			repeating_number = x;
			break;
		}
	}

	if (repeating_number == 0) {
		repeating_number = y;
		missing_number = x;
		return {repeating_number, missing_number};
	}
	else {
		missing_number = y;
	}
	return {repeating_number, missing_number};
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
	vector<int>ans = findMissingRepeatingNumbers(arr);
	printArray_1D(ans);
}