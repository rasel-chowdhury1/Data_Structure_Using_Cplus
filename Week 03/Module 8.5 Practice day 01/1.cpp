#include <bits/stdc++.h>
using namespace std;

vector<int> merging_sort(vector<int> a, vector<int> b)
{
    int idx1 = 0;
    int idx2 = 0;
    int sz = a.size() + b.size();
    
    vector<int> sorted_arr;
    for (int i = 0; i < sz; i++)
    {
        if (idx1 == a.size())
        {
            sorted_arr.push_back(b[idx2]);
            idx2++;
        }
        else if (idx2 == b.size())
        {
            sorted_arr.push_back(a[idx1]);
            idx1++;
        }
        else if (a[idx1] > b[idx2])
        {
            sorted_arr.push_back(a[idx1]);
            idx1++;
        }
        else
        {
            sorted_arr.push_back(b[idx2]);
            idx2++;
        }
    }
    return sorted_arr;
}

int main()
{
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    int n2;
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    vector<int> descending_sort = merging_sort(arr1, arr2);
    
    for (int i = 0; i < descending_sort.size(); i++)
    {
        cout << descending_sort[i] << " ";
    }
}