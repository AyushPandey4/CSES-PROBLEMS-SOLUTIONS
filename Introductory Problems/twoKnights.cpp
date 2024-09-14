#include<bits/stdc++.h>
using namespace std;

int main(){

int n;
cin >> n;
for (int k = 1; k <= n; k++)
{
    long totalways = ((long) k*k*(k*k-1))/2;
    long attackways = 4 * (k-1) * (k-2);
    long ans = totalways - attackways;
    cout << ans  << endl;
}

return 0;
}