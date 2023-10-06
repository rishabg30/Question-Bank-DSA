#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

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

bool check(int mid, vector<int>&arr, int threshold) {
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < mid) {
			ans += 1;
		}
		else if (arr[i] % mid == 0) {
			ans += (arr[i] / mid);
		}
		else {
			ans += (arr[i] / mid) + 1;
		}

		if (ans > threshold) {
			return false;
		}
	}
	return true;
}
int smallestDivisor(vector<int>& arr, int threshold) {
	int n = arr.size();
	//Search space - [1.....max_element]
	int ans = -1;
	int low = 1, high = *max_element(arr.begin(), arr.end());

	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid, arr, threshold) == true) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
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
	int threshold; cin >> threshold;
	cout << smallestDivisor(arr, threshold) << endl;
}