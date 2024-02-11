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
        int x, d1, d2;
        cin >> x >> d1 >> d2;
        int ans = ceil((x * d1 * 1.0) / d2);
        cout << ans << "\n";
    }

    return 0;
}
