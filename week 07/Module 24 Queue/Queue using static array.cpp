#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;
class Queue
{
public:
    int l, r;

    int a[MAX_SIZE];
    Queue()
    {
        l = 0;
        r = -1;
    }
    void enqueue(int value)
    {
        if (r + 1 >= MAX_SIZE)
        {
            cout << "Queue is full\n";
            return;
        }
        r++;
        a[r] = value;
    }

    void dequeue()
    {
        if (l > r)
        {
            cout << "Queue is empty";
            return;
        }
        l++;
    }

    int front()
    {
        if (l > r)
        {
            cout << "Queue is empty";
            return -1;
        }
        return a[l];
    }

    int size()
    {
        return r - l + 1;
    }
};
int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(35);
    q.enqueue(25);
    q.enqueue(34);

    cout << "Queue is: " << q.size() << endl;
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    cout << "Queue is: " << q.size() << endl;
}