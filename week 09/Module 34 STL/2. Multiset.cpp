#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> mt;
    // O(logn)
    mt.insert(5);
    mt.insert(3);
    mt.insert(4);
    mt.insert(7);
    mt.insert(5);
    mt.insert(4);

    // O(n)
    for (auto it : mt)
        cout << it << " ";
    cout << "\n";
    // size = O(1)
    cout << "Set size: " << mt.size() << "\n";

    // O(logn)
    // erase all occurrence
    mt.erase(5);
    for (auto it : mt)
        cout << it << " ";
    cout << "\n";

    // erase a single occurrence
    mt.erase(mt.find(4));
    for (auto it : mt)
        cout << it << " ";
    cout << "\n";

      // O(logn)
    if (mt.find(5) != mt.end())
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
