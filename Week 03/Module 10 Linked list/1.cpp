
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{

public:
    Node *head;
    int size;
    LinkedList()
    {
        head = NULL;
        size = 0;
    }
    void InsertAtHead(int x)
    {
        Node *temp = new Node();
        temp->data = x;
        temp->next = head;
        head = temp;
        size++;
    }
    void Traverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    int getSize()
    {
        return size;
    }
    int getValue(int index)
    {
        if (index >= size)
            return -1;
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    void printReverse(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        printReverse(head->next);
        cout << head->data << " ";
    }
    void swapFirst()
    {
        if (head == NULL || head->next == NULL)
            return;
        Node *first = head;
        Node *second = head->next;

        first->next = second->next;
        second->next = first;
        head = second;
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
    l.Traverse();
    l.swapFirst();
    l.Traverse();
    l.printReverse(l.head);
    return 0;
}