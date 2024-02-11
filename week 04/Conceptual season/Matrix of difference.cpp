#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        list<int> l;
        for (int i = 1; i <= (n * n); i++)
        {
            l.push_back(i);
        }

        int arr[n][n];

        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 2 != 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if ((j + 1) % 2 != 0)
                    {
                        arr[i][j] = l.back();
                        l.pop_back();
                    }
                    else
                    {
                        arr[i][j] = l.front();
                        l.pop_front();
                    }
                }
            }
            else
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if ((j + 1) % 2 != 0)
                    {
                        arr[i][j] = l.front();
                        l.pop_front();
                    }
                    else
                    {
                        arr[i][j] = l.back();
                        l.pop_back();
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}

/*
Tase Case:
2
2
3
*/