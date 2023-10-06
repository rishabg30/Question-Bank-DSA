#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

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

bool check(int mid, vector<int>&bloomDay, int m, int k) {
	int count = 0, count_bouquets = 0;
	for (int i = 0; i < bloomDay.size(); i++) {
		if (bloomDay[i] <= mid) {
			count++;
		}
		else if (bloomDay[i] > mid) {
			count = 0;
		}
		if (count >= k) {
			count_bouquets++;
			count = 0;
		}
		if (count_bouquets == m)return true;
	}
	return count_bouquets >= m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
	int ans = -1;
	int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid, bloomDay, m, k) == true) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
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
	vector<int>bloomDay(n);
	for (int i = 0; i < n; i++) {
		cin >> bloomDay[i];
	}
	int m, k; cin >> m >> k;
	cout << minDays(bloomDay, m, k) << endl;
}