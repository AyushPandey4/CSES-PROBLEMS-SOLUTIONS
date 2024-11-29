#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int mod = 1e9 + 7;

int solve(int i , int j, int n, vector<vector<int>> &mat, vector<vector<int>> &dp) {
	// base case
	if (i == 0 && j == 0) {
		return mat[0][0] == 0 ? 1 : 0;
	}
	if (mat[i][j] == 1) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int up = 0, right = 0;
	if (i > 0) up = solve(i - 1, j, n, mat, dp);
	if (j > 0) right = solve(i, j - 1, n, mat, dp);
	dp[i][j] = (up + right)%mod;
	return dp[i][j];
}


int main() {
	fast_io;

	int n;
	cin >> n;
	vector<string> pathmat(n);
	vector<vector<int>> mat(n, vector<int> (n, 0));

	for (int i = 0; i < n; ++i)
	{
		cin >> pathmat[i];
		for (int j = 0; j < n; ++j)
		{
			if (pathmat[i][j] == '*') mat[i][j] = 1;
		}
	}
	vector<vector<int>> dp(n, vector<int> (n, -1));
	int ans = solve(n - 1, n - 1, n, mat, dp);
	cout << ans << endl;









	return 0;
}
