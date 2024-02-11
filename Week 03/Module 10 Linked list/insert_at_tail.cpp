#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

void Insert_at_Tail(Node *&head, int value)
{
    Node *newnode = new Node(value);
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void print(Node *head)
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
    Node *a = NULL;

    Insert_at_Tail(a, 10);
    Insert_at_Tail(a, 2);

    print(a);
}