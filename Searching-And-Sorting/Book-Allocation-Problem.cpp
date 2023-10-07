#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

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

int check(int mid, vector<int>&arr, int m) {
	int count_students = 1;
	int curr_pages = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (curr_pages + arr[i] <= mid) {
			curr_pages += arr[i];
		}
		else {
			//Give it to next student
			count_students++;
			curr_pages = arr[i];
		}
	}
	return count_students;
}
int findPages(vector<int>& arr, int n, int m) {
	if (m > n)return -1;
	int low = *max_element(arr.begin(), arr.end());
	int high = 0;
	for (int i = 0; i < n; i++) {
		high += arr[i];
	}
	//Search space[max_element_of_array......sum_of_elements_of_array]
	int ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		int students = check(mid, arr, m);
		if (students > m) {
			low = mid + 1;
		}
		else {
			ans = mid;
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
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int m; cin >> m;
	cout << findPages(arr, n, m) << endl;
}