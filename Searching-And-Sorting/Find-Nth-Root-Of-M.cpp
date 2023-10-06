#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int helper_func(int mid, int n, int m) {
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		ans = ans * mid;
		if (ans > m) {
			return 2;
		}
	}
	if (ans == m) {
		return 1;
	}
	return 0;
}
int NthRoot(int n, int m) {
	//Search space [1.....m]
	//0 -> less than mid
	//1 -> equals to mid
	//2 -> greater than mid
	int low = 1, high = m;
	while (low <= high) {
		long long mid = (low + high) / 2;
		int x = helper_func(mid, n, m);

		if (x == 1) {
			return mid;
		}
		else if (x == 0) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	cout << NthRoot(n, m) << endl;
}