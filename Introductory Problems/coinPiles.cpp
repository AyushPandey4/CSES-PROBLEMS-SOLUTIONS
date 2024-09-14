#include <bits/stdc++.h>
using namespace std;

// a>2b and b>2a cause agar twice se bhi larger hua toh ek pakka empty ho jayega jisse condn. false ho jayegi
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long sum = a+b;
        if(sum%3!=0 || a>2*b || b>2*a) cout << "NO" << endl;
        else cout << "YES" << endl; 
    }

    return 0;
}