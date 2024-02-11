#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << (count(s.begin(), s.end(), 'B') * 2 == s.size() ? "YES\n" : "NO\n");
    }
}