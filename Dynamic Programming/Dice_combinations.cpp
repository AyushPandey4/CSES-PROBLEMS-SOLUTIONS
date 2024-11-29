#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int cnt = 0;
    for (int i = 1; i <= 6; i++)
    {
        cnt += solve(n - i, dp);
        cnt %= mod;
    }
    dp[n] = cnt;
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    solve(n, dp);
    cout << dp[n] << endl;

    return 0;
}


// basic implementation of recursion + memorisation