#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            cout << "First duplicate element is " << arr[i] << ", first occurring at index " << mp[arr[i]] << "\n";
            return 0;
        }
        else
        {
            mp[arr[i]] = i;
        }
    }

    return 0;
}
