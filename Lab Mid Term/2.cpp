#include <bits/stdc++.h>
using namespace std;
void remove_duplicate(vector<int> &arr)
{
    // Time Complexity for sorting using library function O(nlogn).
    sort(arr.begin(), arr.end());

    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[i - 1])
        {
            ans.push_back(arr[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    remove_duplicate(arr);
}