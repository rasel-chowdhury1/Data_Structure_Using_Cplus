#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin >> a;
    vector<int> arr(a);
    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }
    int b;
    cin >> b;
    vector<int> ara(b);
    for (int i = 0; i < b; i++)
    {
        cin >> ara[i];
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (arr[i] == ara[j])
            {
                cout << arr[i] << " ";
            }
        }
    }
    return 0;
}