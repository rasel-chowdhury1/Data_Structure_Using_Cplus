#include <bits/stdc++.h>
using namespace std;

int x = 5;
int func(int a, int b)
{
    return a + b;
}
namespace Info
{
    int x = 10;
    int func(int a, int b)
    {
        return a * b;
    }
}

int main()
{
    cout << "This is global X: " << x << '\n';
    cout << "This is namespace X: " << Info::x << "\n";
    int a = 5, b = 4;
    int ans = func(a, b);
    cout << "This is global func: " << ans << "\n";
    int answer = Info::func(a, b);
    cout << "This is Namespace func: " << answer << "\n";
    return 0;
}