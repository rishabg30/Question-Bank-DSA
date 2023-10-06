#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/koko-eating-bananas/

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

bool check(int mid, vector<int>&piles, int h) {
	int count = 0;
	for (int i = 0; i < piles.size(); i++) {
		if (piles[i] % mid == 0) {
			count += (piles[i] / mid);
		}
		else {
			count += (piles[i] / mid) + 1;
		}
		if (count > h) {
			break;
		}
	}
	return count <= h;
}
int minEatingSpeed(vector<int>& piles, int h) {
	int n = piles.size(), ans = 0;
	//Search space [1.......maxElement]
	int x = *max_element(piles.begin(), piles.end());

	int low = 1, high = x;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid, piles, h) == true) {
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
	vector<int>piles(n);
	for (int i = 0; i < n; i++) {
		cin >> piles[i];
	}
	int h; cin >> h;
	cout << minEatingSpeed(piles, h) << endl;
}