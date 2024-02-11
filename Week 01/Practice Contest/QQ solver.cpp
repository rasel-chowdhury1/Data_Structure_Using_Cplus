#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= '9' && s[i] >= '0')
        {
            s[i] -= 48;
        }
    }
    if (s[1] == 'x')
    {
        ans = s[0] * s[2];
    }
    cout << ans;
}