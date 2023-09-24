// #include <bits/stdc++.h>
// using namespace std;
//https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// int longestSubarrayWithSumK(vector<int> arr, long long k) {
// }
// signed main()
// {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int n; cin >> n;
// 	vector<int>arr(n);
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 	}
// 	long long k; cin >> k;
// 	cout << longestSubarrayWithSumK(arr, k) << endl;
// }
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// vector<int>arr = {5, 3, 4, 1, 1};
	// vector<int>arr = {1000000000, 1000000000};
	// vector<int>arr = {6, 5, 3, 9, 2, 7};
	vector<int>arr = {999999999, 1000000000};
	// vector<int>arr = {3, 2, 5, 5, 2, 3};
	//"6" 5 3 3 2 2 ->21
	//5 "5" 3 3 2 2 ->20
	//3 3 "3" 3 2 2 -> 16
	//3 3 3 "9" 2 2 -> 22
	//2 2 2 2"2" 2 ->12
	//2 2 2 2 2 "7" ->17
	cout << maximumSumOfHeights(arr) << endl;
}