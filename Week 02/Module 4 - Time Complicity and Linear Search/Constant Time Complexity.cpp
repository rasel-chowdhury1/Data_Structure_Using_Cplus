#include <bits/stdc++.h>
using namespace std;

/*
O(1)--> constant time Complcity:

Time Complexity = O(1)
Memory Complexity = O(1)

*/
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int maxx, minn, sum, mul;

    maxx = max({a, b, c});
    minn = min({a, b, c});
    sum = a + b + c;
    mul = a * b * c;

    cout << maxx << "\n";
    cout << minn << "\n";
    cout << sum << "\n";
    cout << mul << "\n";

    return 0;
}

