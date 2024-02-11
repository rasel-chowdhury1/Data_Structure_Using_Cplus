#include <bits/stdc++.h>
using namespace std;

/*
Linear Search:
Time Complexity: O(n) 
Memory Complexity: O(n)
*/

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}