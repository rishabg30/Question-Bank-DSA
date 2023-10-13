#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-number-of-nice-subarrays/
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

int countSubarraysWithAtmostkOddNumbers(vector<int>&arr, int k) {
	int n = arr.size();
	int si = 0, ei = 0, count = 0, count_subarrays = 0;

	while (ei < n) {
		if (arr[ei] % 2 != 0) {
			count++;
		}
		ei++;
		while (count > k) {
			int x = arr[si];
			if (x % 2 != 0) {
				count--;
			}
			si++;
		}
		count_subarrays += (ei - si);
	}
	return count_subarrays;
}
int numberOfSubarrays(vector<int>& arr, int k) {
	return countSubarraysWithAtmostkOddNumbers(arr, k) - countSubarraysWithAtmostkOddNumbers(arr, k - 1);
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
	int k; cin >> k;
	cout << numberOfSubarrays(arr, k) << endl;
}