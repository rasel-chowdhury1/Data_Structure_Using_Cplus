#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n;
    vector<int> arr;
    arr.resize(200005);
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        arr[x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            cout << i;
            break;
        }
    }
}