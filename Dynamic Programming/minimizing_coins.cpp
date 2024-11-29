#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &coins, int ind, int target, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target % coins[0] == 0)
            return target / coins[0];
        else
            return 1e9;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int nottake = 0 + solve(coins, ind - 1, target, dp);
    int take = INT_MAX;
    if (target >= coins[ind])
        take = 1 + solve(coins, ind, target - coins[ind], dp);

    dp[ind][target] = min(take, nottake);
    return dp[ind][target];
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    //  solve(coins, n-1, x, dp);
    // cout << dp[n-1][x] << endl;

    // tabulation
    // base case fisrt row fill
    for (int target = 0; target <= x; target++)
    {
        if (target % coins[0] == 0)
            dp[0][target] = target / coins[0];
        else
            dp[0][target] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= x; target++)
        {
            int nottake = 0 + dp[ind - 1][target];
            int take = INT_MAX;
            if (target >= coins[ind])
                take = 1 + dp[ind][target - coins[ind]];

            dp[ind][target] = min(take, nottake);
        }
    }
     if (dp[n - 1][x] >= 1e9)
        cout << -1 << endl;
    else
        cout << dp[n - 1][x] << endl;

    return 0;
}


// classic question on take not take but tabulation is only accepted not memorisation (giving tle)