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
        T *tmp = new T[array_cap * 2];
        int idx = 0;
        for (int i = l; i < array_cap; i++)
        {
            tmp[idx] = a[i];
            idx++;
        }

        for (int i = 0; i < r; i++)
        {
            tmp[idx] = a[i];
            idx++;
        }
        swap(a, tmp);
        delete[] tmp;
    }

    void increase_size()
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
            increase_size();
        }
        r++;
        if (r == array_cap)
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
            cout << "Queue is empty";
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
            cout << "Queue is empty ";
            T a;
            return a;
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

    cout << "Queue is: " << q.size() << endl;
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
    cout << "Queue is: " << q.size() << endl;

    Queue<char> qc;
    qc.enqueue('S');
    qc.enqueue('a');
    cout << "Queue is: " << qc.size() << endl;
    cout << qc.front() << endl;
    qc.dequeue();
    cout << qc.front() << endl;
    qc.dequeue();
    cout << "Queue is: " << qc.size() << endl;

    return 0;
}