#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> revarr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        revarr[i] = arr[n - i - 1];
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << revarr[i] << " ";
    }
    return 0;
}