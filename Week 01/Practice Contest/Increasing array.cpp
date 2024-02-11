#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, moves = 0;
    cin >> n;

    long long arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1] && arr[i] > 0)
        {
            moves += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }
    cout << moves << "\n";

    return 0;
}