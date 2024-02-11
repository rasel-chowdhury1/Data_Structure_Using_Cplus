#include <bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int> arr)
{
    if (arr.size() <= 1)
    {
        return arr;
    }
    int mid = arr.size() / 2;

    vector<int> b;
    vector<int> c;

    for (int i = 0; i < mid; i++)
    {
        b.push_back(arr[i]);
    }

    for (int i = mid; i < arr.size(); i++)
    {
        c.push_back(arr[i]);
    }

    vector<int> sorted_b = merge_sort(b);
    vector<int> sorted_c = merge_sort(c);

    vector<int> sorted_arr;

    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (idx1 == sorted_b.size())
        {
            sorted_arr.push_back(sorted_c[idx2]);
            idx2++;
        }
        else if (idx2 == sorted_c.size())
        {
            sorted_arr.push_back(sorted_b[idx1]);
            idx1++;
        }
        else if (sorted_b[idx1] < sorted_c[idx2])
        {
            sorted_arr.push_back(sorted_b[idx1]);
            idx1++;
        }
        else
        {
            sorted_arr.push_back(sorted_c[idx2]);
            idx2++;
        }
    }
    return sorted_arr;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ara(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
    }
    vector<int> sorted_arr = merge_sort(ara);
    for (int i = 0; i < sorted_arr.size(); i++)
    {
        cout << sorted_arr[i] << " ";
    }
    return 0;
}