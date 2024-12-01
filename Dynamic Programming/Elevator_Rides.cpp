#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const int INF = INT_MAX;

int main() {
    fast_io;
    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int totalMasks = 1 << n;
    vector<pair<int, long long>> dp(totalMasks, {n + 1, 0}); // {min_rides, current_ride_weight}
    dp[0] = {0, 0}; // Base case: no people require 0 rides

    for (int mask = 0; mask < totalMasks; mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue; // Person i is not yet in 'mask'

            int nextMask = mask | (1 << i);
            auto [rides, currWeight] = dp[mask];

            if (currWeight + weights[i] <= x) {
                // Add person i to the current ride
                dp[nextMask] = min(dp[nextMask], {rides, currWeight + weights[i]});
            } else {
                // Start a new ride for person i
                dp[nextMask] = min(dp[nextMask], {rides + 1, weights[i]});
            }
        }
    }

    cout << dp[totalMasks - 1].first + 1 << endl; // Minimum rides for all people
    return 0;
}
