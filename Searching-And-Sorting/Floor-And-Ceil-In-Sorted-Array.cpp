#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

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
int getCeil(vector<int>&arr, int x) {
	int low = 0, high = arr.size() - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] >= x) {
			ans = arr[mid];
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}
int getFloor(vector<int>&arr, int x) {
	int low = 0, high = arr.size() - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] <= x) {
			ans = arr[mid];
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	int ceil = getCeil(arr, x);
	int floor = getFloor(arr, x);
	return make_pair(floor, ceil);
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
	int x; cin >> x;
	pair<int, int>ans = getFloorAndCeil(arr, n, x);
	cout << ans.first << " " << ans.second << endl;
}