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
        // node *a = head;
        // int count = 0;
        // while (a != NULL)
        // {
        //     count++;
        //     a = a->nxt;
        // }
        return size;
    }

    int getValue(int index)
    {
        node *a = head;
        int counter = 0;
        while (a != NULL)
        {
            if (counter == index)
            {
                return (a->data);
            }
            counter++;
            a = a->nxt;
        }
        return -1;
    }

    void swapFirst()
    {
        node *a = head;
        if (getSize() < 1)
        {
            return;
        }
        while (a != NULL && a->nxt != NULL)
        {
            swap(a->data, a->nxt->data);
            return;
        }
    }

    void printReverse(node *head)
    {
        if (head == NULL)
        {
            return;
        }
        printReverse(head->nxt);
        cout << head->data << " ";
    }
};
int main()
{
    LinkedList l;
    cout << l.getSize() << "\n";
    l.InsertAtHead(5);
    cout << l.getSize() << "\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout << l.getSize() << "\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    cout << l.getValue(2) << "\n";

    cout << l.getValue(6) << "\n";

    l.printReverse(l.head);
    cout << "\n";
    l.Traverse();
    l.swapFirst();
    l.Traverse();
    l.printReverse(l.head);
    cout << "\n";

    return 0;
}