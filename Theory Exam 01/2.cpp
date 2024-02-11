#include <bits/stdc++.h>
using namespace std;

// void func()
// {
//     int* p = new int;
//     delete (p);
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << "i = " << i << " ";
        count++;
        for (int j = 1; j <= n; j++)
        {
            cout << "j = " << j << " ";
            count++;
            for (int k = 1; k <= n; k++)
            {
                cout << "k = " << k << " ";
                count++;
            }
        }
        cout<<"\n";
    }

    cout << "ans = " << count << "\n";
}