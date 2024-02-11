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

    vector<pair<int, int>> pr;
    for (int i = 0; i < n; i++)
    {
        pr.push_back(make_pair(arr[i], i));
    }

    sort(pr.begin(), pr.end());

    for (auto it : pr)
    {
        cout << "Value " << it.first << ", Previous Index " << it.second << "\n";
    }
    cout << "\n";

    return 0;
}
