#include <bits/stdc++.h>
using namespace std;
void ultaite_hobe(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a, b;
    cin >> a >> b;
    ultaite_hobe(a, b);
    cout << a << " " << b;
}