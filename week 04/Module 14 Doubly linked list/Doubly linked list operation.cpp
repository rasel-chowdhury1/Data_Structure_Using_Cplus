#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *nextt;
    node *prev;
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

    // O(1)
    node *CreateAnewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nextt = NULL;
        newnode->prev = NULL;
        return newnode;
    }

    // O(1)
    void InsertAtHead(int value)
    {
        size++;
        node *newnode = CreateAnewNode(value);
        if (head == NULL)
        {
            head = newnode;
            return;
        }

        node *a = head;
        newnode->nextt = a;
        a->prev = newnode;
        head = newnode;
    }

    // O(n) ->because of while loop
    void InsertAtIndex(int index, int value)
    {
        if (index == 0)
        {
            InsertAtHead(value);
            return;
        }
        node *a = head;
        int current_index = 0;
        while (current_index != index - 1)
        {
            a = a->nextt;
            current_index++;
        }
        node *newnode = CreateAnewNode(value);
        newnode->nextt = a->nextt;
        newnode->prev = a;
        node *b = a->nextt;
        b->prev = newnode;
        a->nextt = newnode;
        size++;
    }

    // O(n)
    void Delete(int index)
    {
        if (index >= size)
        {
            cout << index << " does not exist.\n";
        }
        node *a = head;
        int current_index = 0;
        while (current_index != index)
        {
            a = a->nextt;
            current_index++;
        }
        node *b = a->prev;
        node *c = a->nextt;
        if (b != NULL)
        {
            b->nextt = c;
        }
        if (c != NULL)
        {
            c->prev = b;
        }
        delete a;
        if (index == 0)
        {
            head = c;
        }
        size--;
    }

    // O(n) ->because of while loop
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

    //O(2*n) = O(n)
    void Reverse()
    {
        if (head == NULL)
        {
            return;
        }
        node *a = head;
        int curr_index = 0;
        while (curr_index != size - 1)
        {
            a = a->nextt;
            curr_index++;
        }

        node *b = head;
        while (b != NULL)
        {
            swap(b->nextt, b->prev);
            b = b->prev;
        }
        head = a;
    }

    // O(1)
    int getSize()
    {
        return size;
    }
};

int main()
{
    DoublyLinkedList dl;
    // dl.InsertAtHead(10);
    // dl.InsertAtHead(5);
    // dl.InsertAtHead(1);
    // dl.Traverse();
    // dl.InsertAtIndex(2, 100);
    // dl.Traverse();
    // dl.Reverse();
    // dl.Traverse();
    cout<<sizeof(node);
    
   
}