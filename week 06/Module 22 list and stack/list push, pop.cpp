#include <bits/stdc++.h>
using namespace std;

void print(list<int> l)
{
    // O(n)
    //  list<int>::iterator a = l.begin();
    auto a = l.begin();
    while (a != l.end())
    {
        cout << *a << " ";
        a++;
    }
    cout << "\n";
}

// worst case: O(n)
void Insert(list<int> &l, int index, int value)
{
    auto it = l.begin(); // O(1)
    advance(it, index);  // O(index)
    l.insert(it, value); // O(1)
}

// worst case: O(n)
void Delete(list<int> &l, int index)
{
    auto it = l.begin(); // O(1)
    advance(it, index);  // O(index)
    l.erase(it);         // O(1)
}

int main()
{
    list<int> l;
    // O(1)
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    print(l);

    // O(1)
    l.push_back(40);
    l.push_back(50);
    print(l);

    // O(1)
    l.pop_back();
    print(l);

    // O(1)
    l.pop_front();
    print(l);

    Insert(l, 2, 100);
    print(l);

    Delete(l, 1);
    print(l);

    cout << l.size() << endl;
}