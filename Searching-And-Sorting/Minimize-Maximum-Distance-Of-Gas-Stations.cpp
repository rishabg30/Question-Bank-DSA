#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
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

int numberOfGasStationsRequired(long double dist, vector<int> &stations) {
	int n = stations.size(); // size of the array
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		int numberInBetween = ((stations[i] - stations[i - 1]) / dist);
		if ((stations[i] - stations[i - 1]) == (dist * numberInBetween)) {
			numberInBetween--;
		}
		cnt += numberInBetween;
	}
	return cnt;
}
double minimiseMaxDistance(vector<int> &stations, int k) {
	int n = stations.size();
	long double low = 0;
	long double high = 0;

	//Search space [0....... max(adjacent distance between two gas stations)]
	for (int i = 0; i < n - 1; i++) {
		high = max(high, (long double)stations[i + 1] - stations[i]);
	}

	long double diff = 1e-6;
	while (high - low > diff) {
		long double mid = (low + high) / 2.0;
		int countGasStations = numberOfGasStationsRequired(mid, stations);
		if (countGasStations > k) {
			low = mid;
		}
		else {
			high = mid;
		}
	}
	return high;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int>stations(n);
	for (int i = 0; i < n; i++) {
		cin >> stations[i];
	}
	int k; cin >> k;
	cout << minimiseMaxDistance(stations, k) << endl;
}