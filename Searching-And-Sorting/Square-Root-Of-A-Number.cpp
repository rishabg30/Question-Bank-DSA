#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/square-root-integral_893351?leftPanelTab=0%3Futm_source%3Dstriver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int floorSqrt(int n) {
	//Search space can be defined as [0....n]
	int low = 0, high = n;
	int ans = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;
		if ((long long)(mid * mid) == (long long)n) {
			return mid;
		}
		else if ((mid * mid) < n) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
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
	cout << floorSqrt(n) << endl;
}