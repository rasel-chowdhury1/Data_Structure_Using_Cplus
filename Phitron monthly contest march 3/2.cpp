#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;

    int odd_sum = 0, even_sum = 0;
    for (int i = n.length() - 1; i >= 0; i--)
    {
        if ((n.length() - i) % 2 == 0)
        {
            even_sum += (n[i] - '0');
        }
        else
        {
            odd_sum += (n[i] - '0');
        }
    }

    int diff = abs(odd_sum - even_sum);
    if (diff % 11 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
