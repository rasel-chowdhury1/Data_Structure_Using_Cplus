#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    
    for (auto it : freq)
    {
        cout << it.first << ": " << it.second << "\n";
    }

    return 0;
}
