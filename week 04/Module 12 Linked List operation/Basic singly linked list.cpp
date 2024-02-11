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
    void traverse()
    {
        node* a = head;
        while (a != NULL)
        {
            cout << a->data << ",";
            a = a->nxt;
        }
        cout << '\n';
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

    void InsertAtAnyIndex(int index, int value)
    {
        if (index < 0 || index > size)
        {
            return;
        }
        if (index == 0)
        {
            InsertAtHead(value);
            return;
        }
        size++;
        node *a = head;
        int current_index = 0;
        while (current_index != index - 1)
        {
            a = a->nxt;
            current_index++;
        }
        node *newnode = Create_New_Node(value);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }

    void DeleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        size--;
        node *a = head;
        head = a->nxt;
        delete a;
    }

    void DeleteAnyIndex(int index)
    {
        if (index < 0 || index > size - 1)
        {
            return;
        }
        if (index == 0)
        {
            DeleteAtHead();
            return;
        }
        size--;
        node *a = head;
        int current_index = 0;
        while (current_index != index - 1)
        {
            a = a->nxt;
            current_index++;
        }
        node *b = a->nxt;
        a->nxt = b->nxt;
        delete b;
    }
};
int main()
{
    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(50);
    l.Traverse();
    l.InsertAtAnyIndex(0, 5);
    l.Traverse();
    l.InsertAtAnyIndex(4, 60);
    l.Traverse();

    l.InsertAtAnyIndex(1, 100);
    l.Traverse();
    cout << l.getSize() << endl;
    l.DeleteAtHead();
    l.Traverse();
    cout << l.getSize() << endl;

    l.DeleteAnyIndex(2);
    l.Traverse();
    cout << l.getSize() << endl;
    

    return 0;
}