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
    int rev;
    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev = 0;
    }

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void InsertAtTail(int value)
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

    void InsertAtHead(int value)
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

    // Push_back O(1)
    void push_back(int value)
    {
        if (rev == 0)
        {
            InsertAtTail(value);
        }
        else
        {
            InsertAtHead(value);
        }
    }

    // push_front O(1)
    void push_front(int value)
    {
        if (rev == 0)
        {
            InsertAtHead(value);
        }
        else
        {
            InsertAtTail(value);
        }
    }

    void DeleteAtTail()
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

    void DeleteAtHead()
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

    // pop_back O(1)
    void pop_back()
    {
        if (rev == 0)
        {
            DeleteAtTail();
        }
        else
        {
            DeleteAtHead();
        }
    }

    // pop_front O(1)
    void pop_front()
    {
        if (rev == 0)
        {
            DeleteAtHead();
        }
        else
        {
            DeleteAtTail();
        }
    }

    // print front O(1)
    int front()
    {
        if (sz == 0)
        {
            cout << "Deque is emtpy ";
            return -1;
        }
        if (rev == 0)
        {
            return head->data;
        }
        else
        {
            return tail->data;
        }
    }

    // print back O(1)
    int back()
    {
        if (sz == 0)
        {
            cout << "Deque is emtpy ";
            return -1;
        }
        if (rev == 0)
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

    // Reverse operation O(1)
    void reverse_deque()
    {
        if (rev == 0)
        {
            rev = 1;
        }
        else
        {
            rev = 0;
        }
    }
};

int main()
{
    Deque d;
    d.push_back(5);
    d.push_back(10);
    d.push_back(15);
    d.push_front(20);
    d.reverse_deque();

    cout << "Deque size: " << d.size() << "\n";
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_back();
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    d.pop_front();
   
    cout << "Front: " << d.front() << " Back: " << d.back() << "\n";
    cout << "Deque size: " << d.size() << "\n";

    return 0;
}