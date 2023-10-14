#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
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
int maxScore(vector<int>& arr, int k) {
	int n = arr.size(), i = 0, j = 0;

	int back_sum = 0, curr_idx = n - k;
	for (int i = curr_idx; i < n; i++) {
		back_sum += arr[i];
	}

	int max_sum = back_sum, front_sum = 0;
	j = n - k;
	while (k--) {
		front_sum += arr[i];
		back_sum -= arr[j];
		i++;
		j++;
		max_sum = max(max_sum, front_sum + back_sum);
	}
	return max_sum;
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
	cout << maxScore(arr, k) << endl;
}