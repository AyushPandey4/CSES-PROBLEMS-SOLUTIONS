#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int min_steps = INT_MAX;
    int temp = n;

    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit > 0)
        { 
            min_steps = min(min_steps, 1 + solve(n - digit, dp));
        }
        temp /= 10;
    }

    dp[n] = min_steps;
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    cout << solve(n, dp) << endl;

    return 0;
}