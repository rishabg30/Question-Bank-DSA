#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int check(int mid, vector<int>&boards, int k) {
	int req_painters = 1;
	int curr_sum = 0;

	for (int i = 0; i < boards.size(); i++) {
		if (curr_sum + boards[i] <= mid) {
			curr_sum += boards[i];
		}
		//New painter required
		else {
			req_painters++;
			curr_sum = boards[i];
		}
	}
	return req_painters;
}
int findLargestMinDistance(vector<int> &boards, int k) {
	int n = boards.size();
	int low = *max_element(boards.begin(), boards.end());
	int high = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		high += boards[i];
	}
	//Search space[max_element_of_array......sum_of_elements_of_array]
	while (low <= high) {
		int mid = (low + high) / 2;
		int req_painters = check(mid, boards, k);
		if (req_painters > k) {
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
	vector<int>boards(n);
	for (int i = 0; i < n; i++) {
		cin >> boards[i];
	}
	int k; cin >> k;
	cout << findLargestMinDistance(boards, k) << endl;

}