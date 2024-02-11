#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());


    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        int left = 0, right = n - 1;
        int flag = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == k)
            {
                cout << "YES\n";
                flag = 1;
                break;
            }
            if (arr[mid] < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (flag == 0)
        {
            cout << "NO\n";
        }
    }

    return 0;
}