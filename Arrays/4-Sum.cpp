#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/4sum/

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

vector<vector<int>> fourSum(vector<int>& arr, int target) {
	int n = arr.size();
	vector<vector<int>>ans;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		if (i > 0 && arr[i] == arr[i - 1]) {
			continue;
		}
		for (int j = i + 1; j < n; j++) {
			if (j > i + 1 && arr[j] == arr[j - 1]) {
				continue;
			}
			int left = j + 1, right = n - 1;

			while (left < right) {
				long long curr_sum = arr[i];
				curr_sum += arr[j];
				curr_sum += arr[left];
				curr_sum += arr[right];
				if (curr_sum < target) {
					left++;
				}
				else if (curr_sum > target) {
					right--;
				}
				else {
					vector<int>quadruplet = {arr[i], arr[j], arr[left], arr[right]};
					ans.push_back(quadruplet);
					left++;
					right--;
					while (left < right && arr[left] == arr[left - 1]) {
						left++;
					}
					while (left < right && arr[right] == arr[right + 1]) {
						right--;
					}
				}
			}
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
	int target; cin >> target;
	vector<vector<int>>ans = fourSum(arr, target);
	printArray_2D(ans);
}