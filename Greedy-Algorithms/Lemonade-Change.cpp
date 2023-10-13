#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/lemonade-change/

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

bool lemonadeChange(vector<int>& bills) {
	int n = bills.size();
	vector<int>change(3, 0);

	for (int i = 0; i < bills.size(); i++) {
		if (bills[i] == 5) {
			change[0]++;
		}
		else if (bills[i] == 10) {
			change[1]++;
			if (change[0] > 0) {
				change[0]--;
			}
			else {
				return false;
			}
		}
		else {
			change[2]++;
			if (change[1] > 0) {
				change[1]--;
				if (change[0] > 0) {
					change[0]--;
				}
				else {
					return false;
				}
			}
			else {
				if (change[0] >= 3) {
					change[0] -= 3;
				}
				else {
					return false;
				}
			}
		}
	}
	return true;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>bills(n);
	for (int i = 0; i < n; i++) {
		cin >> bills[i];
	}
	cout << lemonadeChange(bills) << endl;
}