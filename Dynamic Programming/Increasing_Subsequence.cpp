#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

// int getAns(vector<int>& arr, int n, int ind, int prev_index,
//            vector<vector<int>>& dp) {
// 	// Base condition
// 	if (ind == n)
// 		return 0;

// 	if (dp[ind][prev_index + 1] != -1)
// 		return dp[ind][prev_index + 1];

// 	int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);

// 	int take = 0;

// 	if (prev_index == -1 || arr[ind] > arr[prev_index]) {
// 		take = 1 + getAns(arr, n, ind + 1, ind, dp);
// 	}

// 	return dp[ind][prev_index + 1] = max(notTake, take);
// }

int main() {
	fast_io;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	// vector<vector<int>> dp(n, vector<int>(n + 1, -1));

	// cout << getAns(nums, n, 0, -1, dp) << endl;

	// lis using binary search
	vector<int> temp;
	temp.push_back(nums[0]);

	int len = 1;

	for (int i = 1; i < n; i++) {
		if (nums[i] > temp.back()) {
			// If nums[i] is greater than the last element of temp, extend the subsequence
			temp.push_back(nums[i]);
			len++;
		} else {
			// If nums[i] is not greater, replace the element in temp with nums[i]nums
			int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
			temp[ind] = nums[i];
		}
	}

	cout << len << endl;

	return 0;
}
