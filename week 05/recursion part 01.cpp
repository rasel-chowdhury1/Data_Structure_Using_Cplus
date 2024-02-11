#include <bits/stdc++.h>
using namespace std;
vector<int> coins = {1, 3, 4};

// How many coin need for n taka.
int howManyCoin(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int ans = 1000000;
    for (int i = 0; i < coins.size(); i++)
    {
        if (n >= coins[i])
        {
            ans = min(ans, 1 + howManyCoin(n - coins[i]));
            cout << "coins = " << coins[i] << " ans = " << ans << "\n";
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << howManyCoin(n) << endl;
}