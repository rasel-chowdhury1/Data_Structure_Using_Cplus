#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    int arr[n] = {0};
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
        }
    }
    return 0;
}
