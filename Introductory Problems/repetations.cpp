#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();

    int len = 1;
    int maxlen = 0;
    for (int i = 1; i < n; i++)
    {
        if (str[i - 1] == str[i])
        {
            len++;
        }
        else
        {
            maxlen = max(maxlen, len);
            len = 1;
        }
    }
    maxlen = max(maxlen, len);

    cout << maxlen << endl;

    return 0;
}