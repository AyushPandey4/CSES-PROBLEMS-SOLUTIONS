#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int solve(string& s1, string& s2, int i, int j,
          vector<vector<int>>& dp) {
	// Base cases
	if (i < 0)
		return j + 1;
	if (j < 0)
		return i + 1;


	if (dp[i][j] != -1)
		return dp[i][j];

	if (s1[i] == s2[j])
		return dp[i][j] = 0 + solve(s1, s2, i - 1, j - 1, dp);


	else
		return dp[i][j] =
		           1 + min(solve(s1, s2, i - 1, j - 1, dp),
		                   min(solve(s1, s2, i - 1, j, dp),
		                       solve(s1, s2, i, j - 1, dp)));
}


int main() {
	fast_io;

	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length();
	int m = s2.length();
	vector<vector<int>> dp(n, vector<int>(m, -1));
	cout << solve(s1, s2, n - 1, m - 1, dp) << endl;


	return 0;
}
