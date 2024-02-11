#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity in worst case: O(n^2).
Time Complexity in average case: O(nlogn).
Space Complexity: O(n*logn).
*/


vector<int> quick_sort(vector<int> &arr)
{
    if (arr.size() <= 1)
    {
        return arr;
    }

    int pivot = rand() % (arr.size());

    vector<int> low;
    vector<int> high;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == pivot)
        {
            continue;
        }
        if (arr[i] <= arr[pivot])
        {
            low.push_back(arr[i]);
        }
        else
        {
            high.push_back(arr[i]);
        }
    }

    vector<int> sorted_low = quick_sort(low);
    vector<int> sorted_high = quick_sort(high);

    vector<int> sorted_arr;

    for (int i = 0; i < low.size(); i++)
    {
        sorted_arr.push_back(low[i]);
    }
    sorted_arr.push_back(arr[pivot]);
    for (int i = 0; i < high.size(); i++)
    {
        sorted_arr.push_back(high[i]);
    }

    return sorted_arr;
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

    vector<int> s_arr = quick_sort(arr);

    for (int i = 0; i < s_arr.size(); i++)
    {
        cout << s_arr[i] << " ";
    }

    return 0;
}

/*
Sample Input:

4
6 1 3 2

6
5 6 7 8 0 1


*/