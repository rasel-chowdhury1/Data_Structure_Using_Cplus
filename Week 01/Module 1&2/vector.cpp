#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(i);
    }
    // Insertion:
    a.insert(a.begin() + 0, -1);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    // First digit delete:
    a.erase(a.begin() + 0);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    // Last digite delete:
    a.pop_back();
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}