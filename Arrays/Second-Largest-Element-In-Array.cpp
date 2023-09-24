#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int getSecondLargest(vector<int>&arr) {
	int largestElement = max(arr[0], arr[1]);
	int secondLargest = min(arr[0], arr[1]);

	for (int i = 2; i < arr.size(); i++) {
		if (arr[i] > largestElement) {
			secondLargest = largestElement;
			largestElement = arr[i];
		}
		else if (arr[i] > secondLargest) {
			secondLargest = arr[i];
		}
		else {
			continue;
		}
	}
	return secondLargest;
}

int getSecondSmallest(vector<int>&arr) {
	int smallestElement = min(arr[0], arr[1]);
	int secondSmallest = max(arr[0], arr[1]);
	for (int i = 2; i < arr.size(); i++) {
		if (arr[i] < smallestElement) {
			secondSmallest = smallestElement;
			smallestElement = arr[i];
		}
		else if (arr[i] < secondSmallest) {
			secondSmallest = arr[i];
		}
		else {
			continue;
		}
	}
	return secondSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> arr) {
	int secondLargest = getSecondLargest(arr);
	int secondSmallest = getSecondSmallest(arr);
	return {secondLargest, secondSmallest};
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
	vector<int>ans = getSecondOrderElements(n, arr);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;
}