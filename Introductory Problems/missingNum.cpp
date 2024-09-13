#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = res ^ i;
    }
    for (int i = 0; i < n-1; i++)
    {
        res = res ^ arr[i];
    }

    cout << res << endl;
    

    return 0;
}