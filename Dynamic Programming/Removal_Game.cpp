#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

long long solve(int left, int right,  vector<int>& nums, vector<vector<long long>>& dp) {
	// Base case: if there is only one number, take it
	if (left == right) return nums[left];
	if (dp[left][right] != LLONG_MIN) return dp[left][right];

	// Choose the first element or the last element
	long long takeLeft = nums[left] - solve(left + 1, right, nums, dp);
	long long takeRight = nums[right] - solve(left, right - 1, nums, dp);

	// Return the best option
	return dp[left][right] = max(takeLeft, takeRight);
}

int main() {
	fast_io;

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MIN));
	long long result = solve(0, n - 1, nums, dp);
	long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
	cout << (result + totalSum) / 2 << endl;



	return 0;
}
