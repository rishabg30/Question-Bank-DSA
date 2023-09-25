#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
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

int maxProfit(vector<int>& prices) {
	if (is_sorted(prices.begin(), prices.end(), greater<int>())) {
		return 0;
	}
	int n = prices.size();
	vector<int>max_suffix(n);
	max_suffix[n - 1] = prices[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		max_suffix[i] = max(prices[i], max_suffix[i + 1]);
	}


	int maxProfit = 0, currProfit = 0;
	for (int i = 0; i < n; i++) {
		if (prices[i] == max_suffix[i]) {
			continue;
		}
		else {
			currProfit = max_suffix[i] - prices[i];
		}
		maxProfit = max(maxProfit, currProfit);
	}
	return maxProfit;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>prices(n);
	for (int i = 0; i < n; i++) {
		cin >> prices[i];
	}
	cout << maxProfit(prices);
}