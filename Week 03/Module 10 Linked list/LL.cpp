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

    node *Create_new_node(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void Insert_at_head(int value)
    {
        size++;
        node *a = Create_new_node(value);
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

    int search_Distinct_value(int value)
    {
        node *a = head;
        int index = 0;
        while (a != NULL)
        {
            if (a->data == value)
            {
                return index;
            }
            a = a->nxt;
            index++;
        }
        return -1;
    }

    void search_all_occurrence(int value)
    {
        node *a = head;
        int index = 0;
        while (a != NULL)
        {
            if (a->data == value)
            {
                cout << value << " is found at index " << index << "\n";
            }
            a = a->nxt;
            index++;
        }
    }

    void InsertAnyIndex(int index, int value)
    {
        if (index < 0 || index > size)
        {
            return;
        }
        if (index == 0)
        {
            Insert_at_head(value);
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
        node *newnode = Create_new_node(value);
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
        if (index < 0 || index > size)
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
    l.Insert_at_head(1);
    l.Insert_at_head(2);
    l.Insert_at_head(3);
    l.Insert_at_head(4);
    l.Insert_at_head(5);

    l.Traverse();

    // cout << "3 is found at index = " << l.search_Distinct_value(3) << "\n";

    // l.search_all_occurrence(1);
    cout << l.getSize() << endl;

    l.InsertAnyIndex(0, 20);
    l.Traverse();
    cout << l.getSize() << endl;
    l.InsertAnyIndex(l.getSize(), 50);
    l.Traverse();
    cout << l.getSize() << endl;
    // l.DeleteAtHead();
    l.DeleteAnyIndex(5);
    l.Traverse();
    cout << l.getSize() << endl;
}