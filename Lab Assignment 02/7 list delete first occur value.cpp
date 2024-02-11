#include <bits/stdc++.h>
using namespace std;

void deleteValue(list<int> &l, int value)
{
    auto it = l.begin();
    while (it != l.end())
    {
        if (*it == value)
        {
            l.erase(it);
            return;
        }
        it++;
    }
}

int size(list<int> l)
{
    int sz;
    auto a = l.begin();
    while (a != l.end())
    {
        sz++;
        a++;
    }
    return sz;
}

void print(list<int> l)
{
    auto a = l.begin();
    cout << "[";
    while (a != l.end())
    {
        cout << *a << " ";
        a++;
    }
    cout << "]";
}

int main()
{
    list<int> l;
    l.push_back(7);
    l.push_back(3);
    l.push_back(8);
    l.push_back(4);
    l.push_back(5);
    l.push_back(4);
    cout << "STL list containing ";
    print(l);

    cout << ", value: ";
    int value;
    cin >> value;
    cout << "STL list containing ";
    deleteValue(l, value);
    print(l);
}