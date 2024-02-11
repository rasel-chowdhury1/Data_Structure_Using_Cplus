#include <bits/stdc++.h>
using namespace std;
int isSubset(vector<int> arr1, vector<int> arr2, int n, int m)
{
    int i = 0, j = 0;
    if (m < n)
        return 0;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    while (i < n && j < m)
    {
        if (arr1[i] > arr2[j])
            j++;
        else if (arr1[i] == arr2[j])
        {
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            return 0;
    }
    bool ans = true;
    if (i == n)
        ans = true;
    else
        ans = false;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    if (isSubset(arr1, arr2, n, m) == true)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
