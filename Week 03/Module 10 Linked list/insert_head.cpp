#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void Insert_At_Head(node *&head, int value)
{
    node *newnode = new node(value);
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    newnode->next = head;
    head = newnode;
}

void print(node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    node *head = NULL;

    Insert_At_Head(head, 10);
    Insert_At_Head(head, 20);
    Insert_At_Head(head, 30);
    Insert_At_Head(head, 40);

    print(head);
}