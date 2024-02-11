#include <bits/stdc++.h>
using namespace std;

template <class T>

class Queue
{
public:
    int l, r, sz, array_cap;
    T *a;
    Queue()
    {
        l = 0;
        r = -1;
        sz = 0;
        array_cap = 1;
        a = new T[1];
    }

    void remove_circular()
    {
        int idx = 0;
        T *tmp = new T[array_cap];
        for (int i = l; i <= array_cap; i++)
        {
            tmp[idx] = a[i];
            idx++;
        }
        for (int i = 0; i <= r; i++)
        {
            tmp[idx] = a[i];
            idx++;
        }
        swap(a, tmp);
        delete[] tmp;
    }

    void increase()
    {
        remove_circular();
        T *tmp = new T[array_cap * 2];
        for (int i = 0; i < array_cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        array_cap = array_cap * 2;
        delete[] tmp;
    }

    void enqueue(T value)
    {
        if (sz == array_cap)
        {
            increase();
        }
        sz++;
        r++;
        if (r == array_cap)
        {
            r = 0;
        }
        a[r] = value;
    }

    void dequeue()
    {
        if (sz == 0)
        {
            cout << "Queue is empty.\n";
            return;
        }
        l++;
        if (l == array_cap)
        {
            l = 0;
        }
        sz--;
    }

    T front()
    {
        if (sz == 0)
        {
            cout << "Queue is empty \n";
            T x;
            return x;
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