#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Recursive DP function
long long dp[20][10][2]; // [position][previous_digit][tight]

long long solve(const string &num, int pos, int prevDigit, bool tight, bool started) {
    if (pos == num.size()) return 1; // Reached the end of the number

    if (dp[pos][prevDigit + 1][tight] != -1 && started) return dp[pos][prevDigit + 1][tight];

    int limit = tight ? num[pos] - '0' : 9; // Upper limit for this digit
    long long res = 0;

    for (int d = 0; d <= limit; d++) {
        if (d == prevDigit && started) continue; // No two adjacent digits should be the same
        res += solve(num, pos + 1, d, tight && (d == limit), started || d > 0);
    }

    if (started) dp[pos][prevDigit + 1][tight] = res;
    return res;
}

long long count(long long x) {
    string num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solve(num, 0, -1, true, false);
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << count(b) - count(a - 1) << endl;
    return 0;
}
