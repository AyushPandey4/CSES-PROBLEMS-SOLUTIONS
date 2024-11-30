#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

// // dp concept map <ind, currsum, true/false>
// map <pair<int, int>, bool> mp;


// void solve(vector<int> &arr, set<int> &st, int currsum, int ind) {
// 	if (ind == arr.size()) {
// 		st.insert(currsum);
// 		return;
// 	}
// 	if (mp[ {ind, currsum}])  return;
// 	mp[ {ind, currsum}] = true;

// 	solve(arr, st, currsum, ind + 1);
// 	solve(arr, st, currsum + arr[ind], ind + 1);

// }

int main() {
	fast_io;

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	set<int> st;
	// solve(arr, st, 0, 0);

	// Tabulation concept
	// Maximum possible sum is n * 1000
	const int MAX_SUM = 100000;
	vector<bool> reachable(MAX_SUM + 1, false);
	reachable[0] = true; // Base case: sum 0 is always possible

	for (int coin : arr) {
		for (int sum = MAX_SUM; sum >= coin; --sum) {
			if (reachable[sum - coin]) {
				reachable[sum] = true;
			}
		}
	}

	for (int i = 1; i <= MAX_SUM; ++i) {
		if (reachable[i]) {
			st.insert(i);
		}
	}







	st.erase(0);
	cout << st.size() << endl;

	for (auto it : st) {
		cout << it << " ";
	}
	cout << endl;

	return 0;
}
