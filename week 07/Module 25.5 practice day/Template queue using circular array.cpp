#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;
template <class T>
class Queue
{
public:
    int l, r, sz;
    T a[MAX_SIZE];
    Queue()
    {
        l = 0;
        r = -1;
        sz = 0;
    }

    void enqueue(T value)
    {
        if (sz == MAX_SIZE)
        {
            cout << "Queue is full.\n";
            return;
        }
        r++;
        if (r == MAX_SIZE)
        {
            r = 0;
        }
        a[r] = value;
        sz++;
    }

    void dequeue()
    {
        if (sz == 0)
        {
            cout << "Queue is empty.\n";
            return;
        }
        l++;
        if (l == MAX_SIZE)
        {
            l = 0;
        }
        sz--;
    }

    T front()
    {
        if (sz == 0)
        {
            cout << "Queue is empty ";
            return -1;
        }
        return a[l];
    }

    int size()
    {
        return sz;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(35);
    q.enqueue(25);
    q.enqueue(34);
    q.enqueue(6);
    q.enqueue(10);

    cout << "Queue size: " << q.size() << endl;
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << "Queue size: " << q.size() << endl;

    Queue<char> qt;
    qt.enqueue('a');
    qt.enqueue('b');
    cout << "Queue size: " << qt.size() << endl;
    cout << qt.front() << endl;
    qt.dequeue();
    cout << qt.front() << endl;
}