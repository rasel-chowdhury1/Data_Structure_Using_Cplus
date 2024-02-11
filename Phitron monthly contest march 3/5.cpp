#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 1 << "\n";
    else
    {
        long long a = pow(2, n - 1), b = pow(2, n - 2);
        cout << a * b << "\n";
    }
    return 0;
}