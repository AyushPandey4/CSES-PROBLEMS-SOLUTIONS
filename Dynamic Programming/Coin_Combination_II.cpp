#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    // 1 DP space optimization (Accepted)
    ll dp[x + 1] = {};

    dp[0] = 1;

   
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
        }
    }


    cout << dp[x] << endl;

    return 0;
}
