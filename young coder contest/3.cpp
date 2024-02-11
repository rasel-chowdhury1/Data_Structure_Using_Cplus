#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string res = "";
    int num = 0;
    string l = "";

    for (char c : s)
    {
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        else if (isalpha(c))
        {
            l += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            for (int i = 0; i < num; i++)
            {
                res += l;
            }
            res += c;
            num = 0;
            l = "";
        }
    }

    for (int i = 0; i < num; i++)
    {
        res += l;
    }

    cout << res << "\n";
    return 0;
}
