#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    cout<<"Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<< " ";
    }
    cout<<"\n";

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        int start = 0, end = n - 1;
        int flag = 0;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] == k)
            {
                cout << "YES " << mid << "\n";
                flag = 1;
                break;
            }
            if (arr[mid] < k)
            {
                start = mid + 1;
            }
            else
            {
                // arr[mid]>k
                end = mid - 1;
            }
        }
        if (flag == 0)
        {
            cout << "NO\n";
        }
    }

    return 0;
}
/*
Time Complexity: O(logn).
Space Complexiy: O(n).
*/
/*
Test Case 01:
10 2
3 2 6 4 12 33 17 20 32 11
4 6

Test Case 02:
10 5
3 2 6 4 12 33 17 20 32 11
17 15 10 9 32
*/
