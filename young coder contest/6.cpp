#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int adventure(int N, int W, vector<int> &w, vector<int> &v)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][W];
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> weight(n);
    vector<int> value(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int max_value = adventure(n, w, weight, value);
    cout << max_value << endl;
    return 0;
}
