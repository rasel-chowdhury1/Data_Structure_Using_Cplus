#include <bits/stdc++.h>
using namespace std;

int Counter = 0;
vector<int> merge_sort(vector<int> a, int n, int k)
{
    if (a.size() <= 1)
    {
        return a;
    }

    int mid = a.size() / 2;
    vector<int> b;
    vector<int> c;

    for (int i = 0; i < mid; i++)
        b.push_back(a[i]);

    for (int i = mid; i < a.size(); i++)
        c.push_back(a[i]);

    vector<int> sorted_b = merge_sort(b, n, k);
    vector<int> sorted_c = merge_sort(c, n, k);

    vector<int> sorted_a;
    int idx1 = 0;
    int idx2 = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (idx1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
        else if (idx2 == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else if (sorted_b[idx1] < sorted_c[idx2])
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
    }

    if (sorted_a.size() == n)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            if ((sorted_a[i] + sorted_a[j]) > k)
            {
                j--;
            }
            else if ((sorted_a[i] + sorted_a[j] < k))
            {
                i++;
            }
            else
            {
                Counter++;
                i++;
                j--;
            }
        }
    }

    return sorted_a;
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

    vector<int> ans = merge_sort(arr, n, k);
    cout << Counter << "\n";
    
    return 0;
}