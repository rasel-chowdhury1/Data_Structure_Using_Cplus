#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        list<int> l;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int i = 0;
        while (i < n)
        {
            if (i == 0)
            {
                l.push_back(arr[i]);
                i++;
            }
            else
            {
                if (arr[i] < l.front())
                {
                    l.push_front(arr[i]);
                }
                else
                {
                    l.push_back(arr[i]);
                }
                i++;
            }
        }

        while (!l.empty())
        {
            cout << l.front() << " ";
            l.pop_front();
        }
        cout << "\n";
    }
    
}