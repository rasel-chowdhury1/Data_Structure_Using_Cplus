#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<pair<string, string>, int>> v;
    for (int i = 0; i < n; i++)
    {
        string name, nickname;
        int age;
        cin >> name >> nickname;
        cin >> age;
        v.push_back({{name, nickname}, age});
    }

    for (int i = 0; i < n; i++)
    {
        cout << "First Name: " << v[i].first.first << "\nLast Name: " << v[i].first.second << "\nAge: " << v[i].second << "\n";
    }
}