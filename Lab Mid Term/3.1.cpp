#include <bits/stdc++.h>
using namespace std;

vector<int> quick_sort(vector<int> arr)
{
    int n = arr.size();
    if (n <= 1)
    {
        return arr;
    }

    int pivot = rand() % (n);

    vector<int> left;
    vector<int> right;

    for (int i = 0; i < n; i++)
    {
        if (i == pivot)
        {
            continue;
        }
        else if (arr[i] <= arr[pivot])
        {
            left.push_back(arr[i]);
        }
        else
        {
            right.push_back(arr[i]);
        }
    }

    vector<int> sorted_left = quick_sort(left);
    vector<int> sorted_right = quick_sort(right);

    vector<int> ans;
    for (int i = 0; i < right.size(); i++)
    {
        ans.push_back(sorted_right[i]);
    }
    ans.push_back(arr[pivot]);
    for (int i = 0; i < left.size(); i++)
    {
        ans.push_back(sorted_left[i]);
    }

    return ans;
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

    vector<int> non_increase = quick_sort(arr);
    for (int i = 0; i < non_increase.size(); i++)
    {
        cout << non_increase[i] << " ";
    }
    
    return 0;
}