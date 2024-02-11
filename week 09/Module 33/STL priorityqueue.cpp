#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    // O(logn)
    pq.push(5);
    pq.push(10);
    pq.push(32);

    while (pq.size() != 0)
    {
        // O(1)
        cout << pq.top() << " ";
        // O(logn)
        pq.pop();
    }
    return 0;
}