#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> pre_sum(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre_sum[i + 1] = pre_sum[i] + a[i];
        }

        int ans = -100005;
        for (int i = 0; i < n - k + 1; i++)
        {
            int sum = pre_sum[i + k] - pre_sum[i];
            ans = max(ans, sum);
        }

        cout << ans << "\n";
    }

    return 0;
}
