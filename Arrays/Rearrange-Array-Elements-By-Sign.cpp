#include <bits/stdc++.h>
using namespace std;

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

vector<int> alternateNumbers(vector<int>&arr) {
	int n = arr.size();
	vector<int>positive_array(n / 2);
	vector<int>negative_array(n / 2);
	int x = 0, y = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] >= 0) {
			positive_array[x] = arr[i];
			x++;
		}
		else {
			negative_array[y] = arr[i];
			y++;
		}
	}
	x = 0, y = 0;
	vector<int>ans;
	for (int i = 0; i < arr.size(); i++) {
		if (i % 2 == 0) {
			//Positive elements will come
			ans.push_back(positive_array[x++]);
		}
		else {
			//Negative elements will come
			ans.push_back(negative_array[y++]);
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
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int>ans = alternateNumbers(arr);
	printArray_1D(ans);
}