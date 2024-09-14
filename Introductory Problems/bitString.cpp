#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

int main()
{
    int n;
    cin >> n;

    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = (ans * 2) % MOD; 
    }

    cout << ans << endl;

    return 0;
}