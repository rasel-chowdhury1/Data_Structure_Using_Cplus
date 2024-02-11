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
    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
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
        node<T> *newnode = CreateNewNode(value);
        if (sz == 0)
        {
            head = newnode;
            tail = newnode;
            sz++;
            return;
        }
        newnode->nxt = head;
        head->prv = newnode;
        head = newnode;
        sz++;
    }

    void push_back(T value)
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
            cout << "Deque is empty ";
            T a;
            return a;
        }
        return head->data;
    }

    T back()
    {
        if (sz == 0)
        {
            cout << "Deque is empty ";
            T a;
            return a;
        }
        return tail->data;
    }

    int size()
    {
        return sz;
    }

};

int main()
{
    Deque<int> d;
    d.push_back(5);
    d.push_back(130);
    d.push_back(15);
    d.push_front(20);

    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_back();
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_front();
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_back();
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_front();
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    

}