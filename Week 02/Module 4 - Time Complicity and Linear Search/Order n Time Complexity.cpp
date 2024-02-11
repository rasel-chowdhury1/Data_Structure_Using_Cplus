#include <bits/stdc++.h>
using namespace std;
/*
O(n)--> linear time Complcity/ n variable:

Time Complexity = O(n+1+n+1) = O(2*n+1) = O(2*n) = O(n); N.B = jei jinishta dominate kore oi tai order of ( ) hobe.
Memory Complexity = O(1+n) = O(n);
*/
int main()
{
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxx = a[0];
    int minn = a[0];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        maxx = max(a[i], maxx);
        minn = min(a[i], minn);
        sum = sum + a[i];
    }

    cout << maxx << "\n";
    cout << minn << "\n";
    cout << sum << "\n";

    return 0;
}