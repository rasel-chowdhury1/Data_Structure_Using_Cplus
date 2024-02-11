#include <bits/stdc++.h>
using namespace std;

int maxxElemnet(vector<int> &arr, int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    int maxx = maxxElemnet(arr, n - 1);
    return max(arr[n - 1], maxx);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = maxxElemnet(arr, n);
    cout << ans << endl;

    return 0;
}
