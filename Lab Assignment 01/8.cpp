#include <bits/stdc++.h>
using namespace std;
vector<int> even_generator(vector<int> &arr)
{
    vector<int> even_ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {
            even_ans.push_back(arr[i]);
        }
    }
    return even_ans;
}

int main()
{
    vector<int> arr = {1, 3, 5, 2, 4};
    vector<int> even_arr = even_generator(arr);
    for (int i = 0; i < even_arr.size(); i++)
    {
        cout << even_arr[i] << " ";
    }
    cout << "\n";
    return 0;
}