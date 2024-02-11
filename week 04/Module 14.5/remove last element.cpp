#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *nextt;
    node *previous;
};

class DoublyLinkedList
{
public:
    node *head;
    int size;
    DoublyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    node *create_a_node(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nextt = NULL;
        newnode->previous = NULL;
        return newnode;
    }

    void InsertAtHead(int value)
    {
        size++;
        node *newnode = create_a_node(value);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        node *a = head;
        newnode->nextt = a;
        a->previous = newnode;
        head = newnode;
    }

    void DeleteAtLast()
    {
        if (head == NULL)
        {
            return;
        }
        size--;
        if (head->nextt == NULL)
        {
            head = NULL;
        }
        node *a = head;
        while (a->nextt->nextt != NULL)
        {
            a = a->nextt;
        }
        node *lastnode = a->nextt;
        a->nextt = NULL;
        delete lastnode;
    }

    int getSize()
    {
        return size;
    }

    void Traverse()
    {
        node *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->nextt;
        }
        cout << "\n";
    }
};

int main()
{
    DoublyLinkedList dl;
    dl.InsertAtHead(5);
    dl.InsertAtHead(4);
    dl.InsertAtHead(3);
    dl.InsertAtHead(2);
    dl.InsertAtHead(1);
    dl.Traverse();
    cout << dl.getSize() << "\n";
    dl.DeleteAtLast();
    dl.Traverse();
    cout << dl.getSize() << "\n";
}
