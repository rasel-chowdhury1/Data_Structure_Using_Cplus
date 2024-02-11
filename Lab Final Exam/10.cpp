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

    for (int i = 0; i < m; i++)
    {
        st.insert(ara[i]);
    }

    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}
