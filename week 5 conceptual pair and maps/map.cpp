#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int> mp;
    mp[1] = 5;
    mp[2] = 3;
    mp[0] = 10;

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << "\n";
    }
}