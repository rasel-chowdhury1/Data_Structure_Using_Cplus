#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *nextt;
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

    node *Create_New_node(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nextt = NULL;
        return newnode;
    }

    void AddAtFirstElement(int value)
    {
        size++;
        node *a = Create_New_node(value);
        if (head == NULL)
        {
            head = a;
            return;
        }
        a->nextt = head;
        head = a;
    }

    void printElement()
    {
        node *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->nextt;
        }
        cout << "\n";
    }

    int length()
    {
        return size;
    }

    void DeleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        size--;
        node *a = head;
        head = a->nextt;
        delete a;
    }

    void DeleteAtLast()
    {
        if (head == NULL)
            return;
        size--;
        if (head->nextt == NULL)
        {
            head = NULL;
        }

        node *a = head;
        while (a->nextt->nextt != NULL)
            a = a->nextt;
        node *lastnode = a->nextt;
        a->nextt = NULL;
        delete lastnode;
    }

    void find_ith_Element(int index)
    {
        if (head == NULL)
        {
            return;
        }
        node *a = head;
        int current_index = 0;
        while (a != NULL)
        {
            if (current_index == index)
            {
                cout << a->data << "\n";
                return;
            }
            a = a->nextt;
            current_index++;
        }
    }

    void AddAtlast(int value)
    {
        node *a = Create_New_node(value);
        size++;
        if (head == NULL)
        {
            head = a;
        }
        node *temp = head;
        while (temp->nextt != NULL)
        {
            temp = temp->nextt;
        }
        temp->nextt = a;
    }

    void checkElement(int element)
    {
        node *a = head;
        if (a == NULL)
        {
            return;
        }
        while (a != NULL)
        {
            if (a->data == element)
            {
                cout << "True\n";
                return;
            }
            a = a->nextt;
        }
        cout << "False\n";
    }

    int getIndex(int index)
    {
        if (index < 0 || index > size)
        {
            return -1;
        }
        node *a = head;
        int courrent_index = 0;
        while (index != courrent_index)
        {
            a = a->nextt;
            courrent_index++;
        }
        return a->data;
    }

    void getValueIndex(int index, int value)
    {
        node *a = head;
        if (index < 0 || index > size)
            return;
        int current_index = 0;
        while (index != current_index)
        {
            a = a->nextt;
            current_index++;
        }
        a->data = value;
    }

    void sortAscendingOrder()
    {
        for (int i = 1; i < size; i++)
        {
            int idxx = getIndex(i);
            int j = i - 1;
            while (idxx < getIndex(j) && j >= 0)
            {
               getValueIndex(j + 1, getIndex(j));
                j--;
            }
            getValueIndex(j + 1, idxx);
        }
    }

    void BubbleSort()
    {
        for (int i = 0; i < size; i++)
        {
            node *a = head;
            while (a->nextt != NULL)
            {
                if (a->data > a->nextt->data)
                {
                    swap(a->data,a->nextt->data);
                }
                a = a->nextt;
            }
        }
    }
};

int main()
{
    LinkedList l;
    // for (int i = 5; i >= 1; i--)
    //     l.AddAtFirstElement(i);
    l.AddAtFirstElement(4);
    l.AddAtlast(2);
    l.AddAtlast(5);
    l.AddAtlast(1);
    l.AddAtlast(3);
    l.printElement();

    l.sortAscendingOrder();
    //l.BubbleSort();
   // l.getValueIndex(2,10);
    l.printElement();
}