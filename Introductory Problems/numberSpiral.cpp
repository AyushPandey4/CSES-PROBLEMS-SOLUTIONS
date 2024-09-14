#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> y >> x;
        if (y > x)
        {
            long long ans = (y - 1) * (y - 1);
            long long add = 0;
            if (y % 2 != 0)
            {

                add = x;
            }
            else
            {

                add = 2 * y - x;
            }

            cout << ans + add << "\n";
        }
        else
        {
            long long ans = (x - 1) * (x - 1);
            long long add = 0;
            if (x % 2 == 0)
            {
                add = y;
            }
            else
            {

                add = 2 * x - y;
            }

            cout << ans + add << "\n";
        }
    }

    return 0;
}