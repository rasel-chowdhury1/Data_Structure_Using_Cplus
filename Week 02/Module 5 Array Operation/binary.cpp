#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;

        int left = 0;
        int right = arr.size() - 1;
        int flag = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == k)
            {
                cout << "YES " << mid << " \n";
                flag = 1;
                break;
            }
            else if (arr[mid] > k)
            {
                right = mid + 1;
            }
            else
            {
                left = mid - 1;
            }
        }
        if (flag == 0)
        {
            cout << "NO\n";
        }
    }
}