#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> s;
    // O(logn)
    s.insert(5);
    s.insert(3);
    s.insert(4);
    s.insert(7);
    s.insert(5);

    // O(n)
    for (auto i : s)
        cout << i << " ";
    cout << "\n";
    // size = O(1)
    cout << "Set size: " << s.size() << "\n";

    // O(logn)
    s.erase(7);
    for (auto i : s)
        cout << i << " ";
    cout << "\n";
    cout << "Set size: " << s.size() << "\n";

    // O(logn)
    if (s.find(5) != s.end())
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
