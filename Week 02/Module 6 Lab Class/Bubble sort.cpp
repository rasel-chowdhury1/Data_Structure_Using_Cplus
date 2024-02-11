#include <bits/stdc++.h>
using namespace std;
/*
Memory Complexity: O(n);
Time Complexity: O(n^2)                 //((n-1)*n)/2 = n^2 - n/2;
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
        int last = n - 1 - i;
        bool sorted = true;
        for (int j = 0; j <= last - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        }
        // if (sorted)
        // {
        //     break;
        // }
        cout<<"Consuming i = "<<i<<" :";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<"\n";
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}