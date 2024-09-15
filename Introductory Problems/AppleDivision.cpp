#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(int idx, ll* arr, ll sum1, ll sum2, ll N)
{
    // If we have reached the end, return the difference
    // between the sums
    if (idx == N) {
        return abs(sum1 - sum2);
    }

    // Choose the current apple in group 1
    ll choose
        = solve(idx + 1, arr, sum1 + arr[idx], sum2, N);

    // Choose the current apple in group 2
    ll notChoose
        = solve(idx + 1, arr, sum1, sum2 + arr[idx], N);

    // Return the minimum of both the choices
    return min(choose, notChoose);
}



int main(){
int n;
cin >> n;
ll arr[n];
for (int i = 0; i < n; i++)
{
    cin >> arr[i];
}

cout << solve(0,arr,0,0, n) << endl;


return 0;
}