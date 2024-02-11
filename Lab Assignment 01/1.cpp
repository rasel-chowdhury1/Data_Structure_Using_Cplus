#include <bits/stdc++.h>
using namespace std;

vector<int> quick_sort(vector<int> &arr)
{
    if (arr.size() <= 1)
    {
        return arr;
    }

    int pivot = rand() % (arr.size());

    vector<int> less_than_pivot;
    vector<int> greater_than_pivot;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == pivot)
        {
            continue;
        }
        if (arr[i] <= arr[pivot])
        {
            less_than_pivot.push_back(arr[i]);
        }
        else
        {
            greater_than_pivot.push_back(arr[i]);
        }
    }

    vector<int> sorted_less = quick_sort(less_than_pivot);
    vector<int> sorted_greater = quick_sort(greater_than_pivot);

    vector<int> sorted_arr;
    
    for (int i = 0; i < sorted_greater.size(); i++)
    {
        sorted_arr.push_back(sorted_greater[i]);
    }

    sorted_arr.push_back(arr[pivot]);

    for (int i = 0; i < sorted_less.size(); i++)
    {
        sorted_arr.push_back(sorted_less[i]);
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

    vector<int> non_increasing = quick_sort(arr);

    for (int i = 0; i < non_increasing.size(); i++)
    {
        cout << non_increasing[i] << " ";
    }
    cout << "\n";

    return 0;
}