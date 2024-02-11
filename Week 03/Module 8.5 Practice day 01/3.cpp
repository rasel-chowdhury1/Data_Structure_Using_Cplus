#include <bits/stdc++.h>
using namespace std;

int counter = 0;
vector<int> merge_sort(vector<int> a)
{
    // Base case:
    if (a.size() <= 1)
    {
        return a;
    }

    // Time Complexity for this = log2(n)
    int mid = a.size() / 2;

    vector<int> f_half_a;
    vector<int> s_half_a;

    for (int i = 0; i < mid; i++)
    {
        f_half_a.push_back(a[i]);
    }
    for (int i = mid; i < a.size(); i++)
    {
        s_half_a.push_back(a[i]);
    }

    // Time Complexity for this child = O(n)
    vector<int> sorted_f_half_a = merge_sort(f_half_a);
    vector<int> sorted_s_half_a = merge_sort(s_half_a);

    vector<int> sorted_a;
    int index1 = 0, index2 = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (index1 == sorted_f_half_a.size())
        {
            sorted_a.push_back(sorted_s_half_a[index2]);
            index2++;
        }
        else if (index2 == sorted_s_half_a.size())
        {
            sorted_a.push_back(sorted_f_half_a[index1]);
            index1++;
        }
        else if (sorted_f_half_a[index1] < sorted_s_half_a[index2])
        {
            sorted_a.push_back(sorted_f_half_a[index1]);
            index1++;
        }
        else
        {
            sorted_a.push_back(sorted_s_half_a[index2]);
            index2++;

            counter += sorted_f_half_a.size() - index1;
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

    vector<int> sort_ans = merge_sort(arr);

    cout << counter << endl;
}

/*
Time Complexity: O(nlogn).
Space Complexity: O(n).
*/