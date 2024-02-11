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
        cout << arr[i] << " ";
    }

    for (int j = 0; j < b; j++)
    {
        int flag = 0;

        for (int i = 0; i < a; i++)
        {
            if (arr[i] == ara[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            cout << ara[j] << " ";
        }
    }

    return 0;
}
/*
1st case:
4
1 2 3 5
5
1 6 2 7 3


2nd case:
5
1 2 3 4 5
3
6 7 8
*/