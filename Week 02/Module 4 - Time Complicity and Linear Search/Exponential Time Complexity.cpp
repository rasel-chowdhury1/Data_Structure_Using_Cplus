#include <bits/stdc++.h>
using namespace std;
/*
Exponential Time Complexity:

Time Complexity = O(2^n)
Memory Complexity = O(n)
*/

/*
If called is saved then:
Time Complexity = O(n)
Memory Complexity = O(n)
*/

int called = 0;
int save[100];
int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    //saving called:
    if (save[n] != 0)
    {
        return save[n];
    }
    int x = fibo(n - 1);
    called++;
    int y = fibo(n - 2);
    called++;
    save[n] = x + y;
    return x + y;
}
int main()
{
    int n;
    cin >> n;

    cout << "Fibonacci = " << fibo(n) << "\n";
    cout << "Called = " << called << "\n";

    return 0;
}