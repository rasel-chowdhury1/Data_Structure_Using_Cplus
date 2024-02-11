#include <bits/stdc++.h>
using namespace std;

int b_search(vector<int> &arr, int left, int right, int k)
{
    if (right < left)
        return -1;

    int mid = left + right / 2;

    if (arr[mid] == k)
        return mid;

    if (arr[mid] > k)
        return b_search(arr, left, mid - left, k);

    return b_search(arr, mid + 1, right, k);
}

int count_occur(vector<int> &arr, int n, int k)
{
    int ind = b_search(arr, 0, n - 1, k);

    if (ind == -1)
        return 0;

    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == k)
        count++, left--;

    int right = ind + 1;
    while (right < n && arr[right] == k)
        count++, right++;

    return count;
}

int main()
{

    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    int ans = count_occur(arr, n, k);

    if (ans > 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

/*
Sample input 1-
7
1 3 4 6 6 9 17
6

Sample input 2-
10
1 2 3 4 5 6 7 8 9 10
5


*/
