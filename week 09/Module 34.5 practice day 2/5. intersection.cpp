#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    vector<int> ara(m);
    for (int i = 0; i < m; i++)
    {
        cin >> ara[i];
    }

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        if (st.find(ara[i]) != st.end())
        {
            ans.push_back(ara[i]);
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}
