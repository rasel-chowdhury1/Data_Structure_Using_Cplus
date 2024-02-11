#include <bits/stdc++.h>
using namespace std;

void adder_sort(vector<int> arr)
{
    deque<int> dq;
    for (int i = 0; i < arr.size(); i++)
    {
        dq.push_back(arr[i]);
    }

    vector<int> ans;

    while (!dq.empty())
    {
        if (dq.front() < dq.back())
        {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        else
        {
            ans.push_back(dq.back());
            dq.pop_back();
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

    adder_sort(arr);
    
    return 0;
}
