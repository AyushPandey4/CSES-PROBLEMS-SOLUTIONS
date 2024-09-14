#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    map<char, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[s[i]]++;
    }

    int cnt = 0;
    for (auto it : mpp)
    {
        if (it.second % 2 != 0)
            cnt++;
    }
    if (cnt > 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int left = 0, right = n - 1;
    for (auto it : mpp)
    {
        if (it.second % 2 != 0)
        {
            s[n / 2] = it.first;
            it.second = it.second - 1;
        }
        while (it.second > 0)
        {
            s[left++] = it.first;
            s[right--] = it.first;
            it.second = it.second - 2;
        }
    }
    cout << s << endl;

    return 0;
}