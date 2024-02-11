#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *nxt;
    node *prv;
};

class Deque
{
public:
    node *head;
    node *tail;
    int sz;
    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    // Push_back O(1)
    void push_back(int value)
    {
        node *newnode = CreateNewNode(value);
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

    // push_front O(1)
    void push_front(int value)
    {
        node *newnode = CreateNewNode(value);
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

    // pop_back O(1)
    void pop_back()
    {
        if (sz == 0)
        {
            cout << "Deque is empty.\n";
            return;
        }
        if (sz == 1)
        {
            delete tail; // head or tail ekta delete korlei hobe
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node *a = tail;
        tail = tail->prv;
        delete a;
        tail->nxt = NULL;
        sz--;
    }

    // pop_front O(1)
    void pop_front()
    {
        if (sz == 0)
        {
            cout << "Deque is empty.\n";
            return;
        }
        if (sz == 1)
        {
            delete head; // head or tail ekta delete korlei hobe
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node *a = head;
        head = head->nxt;
        delete a;
        head->prv = NULL;
        sz--;
    }

    // print front O(1)
    int front()
    {
        if (sz == 0)
        {
            cout << "Deque is emtpy ";
            return -1;
        }
        return head->data;
    }

    // print back O(1)
    int back()
    {
        if (sz == 0)
        {
            cout << "Deque is emtpy ";
            return -1;
        }
        return tail->data;
    }

    int size()
    {
        return sz;
    }

    int maxx()
    {
        if (sz == 0)
        {
            cout << "Deque is empty";
            return -1;
        }
        node *a = head;
        int Maxx = a->data;
        while (a != NULL)
        {
            Maxx = max(Maxx, a->data);
            a = a->nxt;
        }
        return Maxx;
    }
};

int main()
{
    Deque d;
    d.push_back(5);
    d.push_back(130);
    d.push_back(15);
    d.push_front(20);

    cout << "Max: " << d.maxx() << "\n";
    cout << "Deque size: " << d.size() << "\n";
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";

    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_back();
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_front();
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    cout << "Deque size: " << d.size() << "\n";

    return 0;
}