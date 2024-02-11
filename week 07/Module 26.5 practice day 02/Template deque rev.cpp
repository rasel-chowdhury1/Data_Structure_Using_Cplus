#include <bits/stdc++.h>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node *nxt;
    node *prv;
};

template <class T>
class Deque
{
public:
    node<T> *head;
    node<T> *tail;
    int sz;
    int rv;
    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rv = 0;
    }

    node<T> *CreateNewNode(T value)
    {
        node<T> *newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void push_front(T value)
    {

        if (rv == 0)
        {
            revfront(value);
        }
        else
        {
            revback(value);
        }
    }

    // for reverse O(1)
    void revfront(T value)
    {
        node<T> *newnode = CreateNewNode(value);
        if (sz == 0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        head->prv = newnode;
        newnode->nxt = head;
        head = newnode;
        sz++;
    }

    void push_back(T value)
    {

        if (rv == 0)
        {
            revback(value);
        }
        else
        {
            revfront(value);
        }
    }

    // for reverse O(1)
    void revback(T value)
    {
        node<T> *newnode = CreateNewNode(value);
        if (sz == 0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }

        tail->nxt = newnode;
        newnode->prv = tail;
        tail = newnode;
        sz++;
    }

    void pop_back()
    {

        if (rv == 0)
        {
            poprevBack();
        }
        else
        {
            poprevFront();
        }
    }

    // for reverse O(1)
    void poprevBack()
    {
        if (sz == 0)
        {
            cout << "Deque is empty.\n";
            return;
        }
        if (sz == 1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }

        node<T> *a = tail;
        tail = tail->prv;
        delete a;
        tail->nxt = NULL;
        sz--;
    }

    void pop_front()
    {

        if (rv == 0)
        {
            poprevFront();
        }
        else
        {
            poprevBack();
        }
    }

    // for reverse O(1)
    void poprevFront()
    {
        if (sz == 0)
        {
            cout << "Deque is empty.\n";
            return;
        }
        if (sz == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }

        node<T> *a = head;
        head = head->nxt;
        delete a;
        head->prv = NULL;
        sz--;
    }

    T front()
    {
        if (sz == 0)
        {
            cout << "Deque is empty";
            T a;
            return a;
        }
        if (rv == 0)
        {
            return head->data;
        }
        else
        {
            return tail->data;
        }
    }

    T back()
    {
        if (sz == 0)
        {
            cout << "Deque is empty";
            T a;
            return a;
        }
        if (rv == 0)
        {
            return tail->data;
        }
        else
        {
            return head->data;
        }
    }

    int size()
    {
        return sz;
    }

    void reverse()
    {
        if (rv == 0)
        {
            rv = 1;
        }
        else
        {
            rv = 0;
        }
    }

};

int main()
{
    Deque<int> d;
    d.push_back(5);
    d.push_back(10);
    d.push_back(15);
    d.push_front(20);
    d.reverse();


    cout << "Deque size: " << d.size() << "\n";
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_back();
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_front();

    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    cout << "Deque size: " << d.size() << "\n";

    Deque<char> dc;
    dc.push_back('S');
    dc.push_back('U');
    dc.push_back('J');
    dc.push_front('M');
    dc.push_front('D');
    dc.reverse();
    cout << "Deque size: " << dc.size() << "\n";
    cout << "Front: " << dc.front() << " Back: " << dc.back() << "\n";
    dc.pop_back();
}