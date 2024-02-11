#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(nlogn);
Memory Complexity: O(n);
*/
int main()
{
    int n;
    cin >> n;
    vector<int> primes;
    vector<bool> visited(n + 1);
    for (int i = 2; i <= n; i++)
    {
        if (!visited[i])
        {
            primes.push_back(i);
            for (int x = 2; i * x <= n; x++)
            {
                visited[i * x] = true;
            }
        }
    }

    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
    }
}