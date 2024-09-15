#include <bits/stdc++.h>
using namespace std;

set<string> solve(string s)
{
    sort(s.begin(), s.end());
    set<string> uniquestring;
    uniquestring.insert(s);
    while (next_permutation(s.begin(), s.end()))
    {
        uniquestring.insert(s);
    }
    return uniquestring;
}

int main()
{
    string s;
    cin >> s;
    set<string> str = solve(s);
    cout << str.size() << endl;
    for(auto it : str){
        cout << it << endl;
    }
    return 0;
}