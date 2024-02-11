#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *nxt;
    Node *prv;
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int sz;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    Node *CreateNewNode(int value)
    {
        Node *newnode = new Node;
        newnode->value = value;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }

    void insertHead(int value)
    {
        sz++;
        Node *a = CreateNewNode(value);
        if (head == NULL)
        {
            head = a;
            tail = a;
            return;
        }
        Node *b = head;
        a->nxt = b;
        b->prv = a;
        head = a;
    }

    void insertTail(int value)
    {
        sz++;
        Node *a = CreateNewNode(value);
        if (head == NULL)
        {
            head = a;
            tail = a;
            return;
        }
        Node *b = tail;
        tail->nxt = a;
        a->prv = tail;
        tail = a;
    }

    void insertMid(int value)
    {
        int mid = sz / 2;
        Node *a = CreateNewNode(value);
        if (head == NULL)
        {
            head = a;
            tail = a;
            sz++;
            return;
        }
        sz++;
        int cur_idx = 0;
        Node *b = head;
        while (cur_idx != mid - 1)
        {
            b = b->nxt;
            cur_idx++;
        }

        a->nxt = b->nxt;
        b->nxt->prv = a;
        b->nxt = a;
        a->prv = b;
    }

    void print()
    {
        Node *a = head;
        while (a != NULL)
        {
            cout << a->value << " ";
            a = a->nxt;
        }
        cout << "\n";
    }
};
int main()
{
    LinkedList a;
    LinkedList b;

    a.insertHead(1);
    a.insertTail(5);
    a.insertMid(3);
    a.insertHead(0);
    a.insertTail(10);
    a.print(); // prints  0 1 3 5 10

    b.insertHead(10);
    b.insertTail(50);
    b.insertMid(30);
    b.insertHead(9);
    b.insertTail(100);
    b.print(); // prints  9 10 30 50 100

  
}
