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

    void insertInfront(int value)
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
    dl.insertInfront(5);
    dl.insertInfront(4);
    dl.insertInfront(3);
    dl.insertInfront(2);
    dl.insertInfront(1);
    dl.Traverse();
    cout << dl.getSize() << "\n";
    dl.insertInfront(0);
    cout << dl.getSize() << "\n";
    dl.Traverse();
}
