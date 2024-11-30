#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long countWays(int index, int sum, vector<vector<long long>>& dp, int n) {
    // Base cases
    if (sum == 0) return 1;          
    if (sum < 0 || index > n) return 0;  

   
    if (dp[index][sum] != -1) return dp[index][sum];

    long long include = countWays(index + 1, sum - index, dp, n);
    long long exclude = countWays(index + 1, sum, dp, n);

    return dp[index][sum] = (include + exclude) % MOD;
}

int main() {
    int n;
    cin >> n;

   
    int total_sum = n * (n + 1) / 2;

    
    if (total_sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int target = total_sum / 2;

   
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));

  
    long long result = countWays(1, target, dp, n);

    // Divide by 2 because each solution is counted twice
    cout << (result * 500000004) % MOD << endl;  // 500000004 = modular inverse of 2 (mod 1e9+7)

    return 0;
}
