#include <bits/stdc++.h>
using namespace std;

int flag = 0;

vector<int> merging(vector<int> arr, int k)
{
    if (arr.size() <= 1)
    {
        return arr;
    }
    int mid = arr.size() / 2;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < mid; i++)
    {
        a.push_back(arr[i]);
    }
    for (int i = mid; i < arr.size(); i++)
    {
        b.push_back(arr[i]);
    }
    vector<int> sorted_a = merging(a, k);
    vector<int> sorted_b = merging(b, k);

    vector<int> sorted_arr;

    int idx = 0, idx1 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (idx == sorted_a.size())
        {
            sorted_arr.push_back(sorted_b[idx1]);
            idx1++;
        }
        else if (idx1 == sorted_b.size())
        {
            
            sorted_arr.push_back(sorted_a[idx]);
            idx++;
        }
        else if (sorted_a[idx] < sorted_b[idx1])
        {
            if (sorted_a[idx] + sorted_b[idx1] == k)
            {
                flag++;
            }

            sorted_arr.push_back(sorted_a[idx]);
            idx++;
        }
        else
        {
            if (sorted_a[idx] + sorted_b[idx1] == k)
            {
                flag++;
            }
            sorted_arr.push_back(sorted_b[idx1]);
            idx1++;
        }
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
    int k;
    cin >> k;

    vector<int> search = merging(arr, k);

    if (flag == 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

/*

4
6 1 3 2
5
6
5 6 7 8 0 1
16

*/