#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    // O(logn)
    mp["cat"] = 20;
    mp["vera"] = 19;
    mp["goru"] = 22;

    // O(n)
    for (auto it : mp)
        cout << it.first << " " << it.second << endl;

    // O(1)
    cout << mp.size() << "\n";
    return 0;
}