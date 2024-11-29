#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int solve(int ind, int n, int x, vector<int> &price, vector<int> &pages, vector<vector<int>> &dp) {
	// base case
	if (ind == 0) {
		if (price[0] <= x) return pages[0];
		else return 0;
	}
	if (x == 0) return 0;
	if (dp[ind][x] != -1) return dp[ind][x];
	int takepages = -1e9;
	// take book
	if (price[ind] <= x) takepages = pages[ind] + solve(ind - 1, n, x - pages[ind], price, pages, dp);
	// not take book
	int nottakepages = 0 + solve(ind - 1, n, x, price, pages, dp);
	return max(takepages, nottakepages);
}


int main() {
	fast_io;
	int n, x;
	cin >> n >> x;
	vector<int> price(n);
	vector<int> pages(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> price[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> pages[i];
	}


	// vector<vector<int>> dp(n, vector<int> (x + 1, -1));
	// int ans = solve(n - 1, n, x, price, pages, dp);
	// cout << ans << endl;




	// tabulation
	// for (int j = 0; j <= x; ++j)
	// {
	// 	if (price[0] <= j) dp[0][j] = price[0];
	// }
	// for (int i = 1; i < n; ++i) {
	// 	for (int j = 0; j <= x; ++j) {
	// 		dp[i][j] = dp[i - 1][j];
	// 		if (price[i] <= j) {
	// 			dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + pages[i]);
	// 		}
	// 	}
	// }
	// cout << dp[n - 1][x] << endl;



	// 1D DP Optimization (Accepted)
	 vector<int> dp(x + 1, 0);

    // Process each book
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= price[i]; --j) { // Traverse backward to avoid overwriting
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }

    // The answer is the maximum pages with full budget
    cout << dp[x] << endl;

	return 0;
}
