#include <bits/stdc++.h>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node *nxt;
};
template <class T>
class Queue
{
public:
    node<T> *head;
    node<T> *tail;
    int sz;
    Queue()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node<T> *CreateNewNode(int value)
    {
        node<T> *newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void enqueue(T value)
    {
        sz++;
        node<T> *a = CreateNewNode(value);
        if (head == NULL)
        {
            head = a;
            tail = a;
            return;
        }
        tail->nxt = a;
        tail = a;
    }

    void dequeue()
    {
        if (sz == 0)
        {
            cout << "Queue is empty.\n";
            return;
        }
        if (sz == 1)
        {
            delete head;
            sz--;
            head = NULL;
            tail = NULL;
            return;
        }
        sz--;
        node<T> *a = head;
        head = a->nxt;
        delete a;
    }

    T front()
    {
        if (sz == 0)
        {
            cout << "Queue is empty.\n";
            T x;
            return x;
        }
        return head->data;
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