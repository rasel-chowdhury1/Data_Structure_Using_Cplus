#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            cout << mp[arr[i]] << "\n";
        }
        else
        {
            cout << "-1\n";
        }
        mp[arr[i]] = i;
    }

    return 0;
}
