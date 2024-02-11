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
    // Head
    node *head;
    LinkedList()
    {
        head = NULL;
    }

    // Create a new node with data = value and nxt = NULL.
    node *Create_New_Node(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    // Insert new value at head.
    void Insert_At_Head(int value)
    {
        node *a = Create_New_Node(value);
        if (head == NULL)
        {
            head = a;
            return;
        }
        // if head is not NULL
        a->nxt = head;
        head = a;
    }

    // Prints all linked list
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

    // Search for single value
    int Search_Distinct_Value(int value)
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

    // Search all possible occurrence
    void Search_All_Value(int value)
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
};
int main()
{
    LinkedList l;
    l.Insert_At_Head(30);
    l.Insert_At_Head(10);
    l.Insert_At_Head(20);
    l.Insert_At_Head(30);

    l.Traverse();

    cout << "20 is found at index " << l.Search_Distinct_Value(20) << "\n";
    cout << "5 is found at index " << l.Search_Distinct_Value(5) << "\n";
    cout << "10 is found at index " << l.Search_Distinct_Value(10) << "\n";

    l.Search_All_Value(30);
}