#include <bits/stdc++.h>
using namespace std;

vector<string> merge_sort(vector<string> &st)
{
    if (st.size() <= 1)
        return st;
    int mid = st.size() / 2;
    vector<string> first_half;
    vector<string> second_half;
    for (int i = 0; i < mid; i++)
    {
        first_half.push_back(st[i]);
    }

    for (int i = mid; i < st.size(); i++)
    {
        second_half.push_back(st[i]);
    }

    vector<string> sorted_first = merge_sort(first_half);
    vector<string> sorted_second = merge_sort(second_half);

    vector<string> ans;
    int idx1 = 0, idx2 = 0;

    for (int i = 0; i < st.size(); i++)
    {
        if (idx1 == sorted_first.size())
        {
            ans.push_back(sorted_second[idx2]);
            idx2++;
        }
        else if (idx2 == sorted_second.size())
        {
            ans.push_back(sorted_first[idx1]);
            idx1++;
        }
        else if (sorted_first[idx1] < sorted_second[idx2])
        {
            ans.push_back(sorted_first[idx1]);
            idx1++;
        }
        else
        {
            ans.push_back(sorted_second[idx2]);
            idx2++;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> st(n);
    for (int i = 0; i < n; i++)
    {
        cin >> st[i];
    }

    vector<string> ans = merge_sort(st);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
