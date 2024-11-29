#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
 
// int solve(vector<int> &coins, int ind, int target, vector<vector<int>> &dp)
// {
//     if (target == 0)
//         return 1;
//     if (ind == 0)
//     {
//         if (target % coins[0] == 0)
//             return 1;
//         else
//             return 0;
//     }
//     if (dp[ind][target] != -1)
//         return dp[ind][target];
 
//     int nottake = solve(coins, ind - 1, target, dp);
//     int take = 0;
//     if (target >= coins[ind])
//         take = solve(coins, ind, target - coins[ind], dp);
 
//     dp[ind][target] = (take + nottake) % mod;
//     return dp[ind][target];
// }
 
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    // vector<vector<long long>> dp(n, vector<long long>(x + 1, 0));
    // cout <<  solve(coins, n-1, x, dp) << endl;
 
    // tabulation
    // for (int target = 0; target <= x; target++)
    // {
    //     if (target % coins[0] == 0)
    //         dp[0][target] = 1;
    //     else
    //         dp[0][target] = 0;
    // }
 
    // for (int ind = 1; ind < n; ind++)
    // {
    //     for (int target = 0; target <= x; target++)
    //     {
    //         long long nottake = dp[ind - 1][target];
    //         long long take = 0;
    //         if (target >= coins[ind])
    //             take = dp[ind][target - coins[ind]];
 
    //         dp[ind][target] = (take + nottake) % mod;
    //     }
    // }
    // cout << dp[n - 1][x] << endl;
 
    // space optimization 2 DP solution 
 
    // vector<long long> prev(x + 1, 0), curr(x + 1, 0);
    // prev[0] = 1;
    // for (int ind = 1; ind < n; ind++)
    // {
    //     for (int target = 0; target <= x; target++)
    //     {
    //         long long nottake = prev[target];
    //         long long take = 0;
    //         if (target >= coins[ind])
    //             take = prev[target - coins[ind]];
 
    //         curr[target] = (take + nottake) %mod;
    //     }
    //     prev = curr;
    // }
    // cout << prev[x] << endl;

    // 1 DP space optimization (Accepted)
    ll dp[x + 1] = {};

    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] > i)
                continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }
    
    cout << dp[x] << endl;
 
    return 0;
}
