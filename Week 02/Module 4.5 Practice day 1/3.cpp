#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            s[i] += 1;
        }
        if (s[i] > 122)
        {
            s[i] -= 122;
            s[i] += 96;
        }
    }

    cout << s;

    return 0;
}