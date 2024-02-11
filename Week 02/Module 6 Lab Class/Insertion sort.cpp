#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(n^2);
Memory Complexity: O(n);
*/
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int idx = i;
        while (idx >= 1)
        {
            if (arr[idx - 1] > arr[idx])
            {
                swap(arr[idx - 1], arr[idx]);
                idx--;
            }
            else
            {
                break;
            }
        }
    }
    cout << "After soring:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}