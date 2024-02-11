#include <bits/stdc++.h>
using namespace std;

int isPal(string s)
{
    deque<char> d;
    for (int i = 0; i < s.size(); i++)
    {
        d.push_back(s[i]);
    }
    while (d.size() > 1)
    {
        if (d.front() != d.back())
        {
            return 0;
        }
        d.pop_front();
        d.pop_back();
    }
    return 1;
}

int main()
{
    string str;
    cin >> str;
    if (isPal(str) == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}