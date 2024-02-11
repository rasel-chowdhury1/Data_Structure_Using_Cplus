#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);

    // empty O(1)
    cout << q.empty() << endl;

    // size O(1)
    cout << "Queue size: " << q.size() << endl;

    // front O(1)
    cout << q.front() << endl;

    // pop O(1)
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.empty() << endl;

    queue<char> q2;
    q2.push('S');
    q2.push('U');
    cout << q2.front() << endl;
    q2.pop();
    cout << q2.front() << endl;
    q2.pop();
}