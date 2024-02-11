#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a, b;
    cin >> a >> b;

    arr.erase(arr.begin() + a - 1, arr.begin() + b);
    
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/*
6
1 4 6 2 8 7
2 4


10
1 3 5 7 9 2 4 6 8 10
1 5


*/

