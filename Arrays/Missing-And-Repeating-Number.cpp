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
		X0R ^= (i + 1);
	}

	//Calculating the differ bit in the number
	int temp = XOR, count = 0;
	while (temp) {
		if ((temp & 1) == 1) {
			break;
		}
		else {
			count++;
			temp = temp >> 1;
		}
	}

	// Segregate them into two sets
	// 1st Set - elements containing their first bit as 1
	// 2nd Set - elements containing their first bit as 0

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