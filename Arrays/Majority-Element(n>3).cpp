#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/majority-element-ii/

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

vector<int> majorityElement(vector<int>& arr) {
	int n = arr.size();
	if (n == 1) {
		return {arr[0]};
	}

	int element1 = 0, element2 = 0, count1 = 0, count2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == element1) {
			count1++;
		}
		else if (arr[i] == element2) {
			count2++;
		}
		else if (count1 == 0) {
			element1 = arr[i];
			count1 = 1;
		}
		else if (count2 == 0) {
			element2 = arr[i];
			count2 = 1;
		}
		else {
			count1--;
			count2--;
		}
	}

	int freq_element1 = 0, freq_element2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == element1) {
			freq_element1++;
		}
		else if (arr[i] == element2) {
			freq_element2++;
		}
	}

	vector<int>ans;
	if (freq_element1 > (n / 3)) {
		ans.push_back(element1);
	}
	if (freq_element2 > (n / 3)) {
		ans.push_back(element2);
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
	vector<int>ans = majorityElement(arr);
	printArray_1D(ans);
}