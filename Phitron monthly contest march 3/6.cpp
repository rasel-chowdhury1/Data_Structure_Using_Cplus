#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin >> n;
    vector<int> arr(n + 1);
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            st.insert(i);
        }
    }

    long long int Q;
    cin >> Q;
    while (Q--)
    {
        int L, R;
        cin >> L >> R;
        auto it = st.lower_bound(L);
        if (it != st.end() && *it <= R)
        {
            cout << 0 << "\n";
        }
        else
            cout << 1 << "\n";
    }
    return 0;
}