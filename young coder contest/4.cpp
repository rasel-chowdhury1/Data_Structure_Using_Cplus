#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, flag = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                even = arr[i];
                if (odd != 0)
                {
                    if (odd <= even)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else
            {
                odd = arr[i];
                if (even != 0)
                {
                    if (even <= odd)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
