#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *nxt;
};

class LinkedList
{
public:
    node *head;
    int size;
    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    node *Create_New_Node(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void InsertAtHead(int value)
    {
        size++;
        node *a = Create_New_Node(value);
        if (head == NULL)
        {
            head = a;
            return;
        }
        a->nxt = head;
        head = a;
    }

    void Traverse()
    {
        node *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << "\n";
    }

    int getSize()
    {
        return size;
    }

    void InsertAfterValue(int value, int data)
    {
        node *a = head;
        while (a != NULL)
        {
            if (a->data == value)
            {
                break;
            }
            a = a->nxt;
        }
        if (a == NULL)
        {
            cout << value << " doesn't exist in linked-list.\n";
            return;
        }

        size++;
        node *newnode = Create_New_Node(data);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }

    void printReverseRecursive(node *a)
    {
        if (a == NULL)
        {
            return;
        }
        printReverseRecursive(a->nxt);
        cout << a->data << " ";
    }
    void printReverse()
    {
        printReverseRecursive(head);
        cout << "\n";
    }
};

int main()
{
    LinkedList l;
    l.InsertAtHead(50);
    l.InsertAtHead(40);
    l.InsertAtHead(30);
    l.InsertAtHead(10);
    l.InsertAfterValue(10, 20);
    l.Traverse();
    l.printReverse();
    l.Traverse();
}