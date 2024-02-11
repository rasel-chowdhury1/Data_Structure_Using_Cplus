#include <bits/stdc++.h>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node<T> *nxt;
};

template <class T>
class singlylinkedlist
{
public:
    node<T> *head;
    int sz;
    singlylinkedlist()
    {
        head = NULL;
        sz = 0;
    }

    node<T> *CreateNewNode(T value)
    {
        node<T> *newnode = new node<T>;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void InsertAtHead(T value)
    {
        sz++;
        node<T> *newnode = CreateNewNode(value);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        newnode->nxt = head;
        head = newnode;
    }

    void DeleteAtHead()
    {
        if (sz == 0)
        {
            cout << "Stack is empty.";
            return;
        }
        if (sz == 1)
        {
            delete head;
            head = NULL;
            sz--;
            return;
        }
        sz--;
        node<T> *newnode = head;
        head = head->nxt;
        delete newnode;
    }

    int size()
    {
        return sz;
    }
};

template <class T>
class Stack
{
public:
    singlylinkedlist<T> sl;
    Stack()
    {
    }

    void push(T value)
    {
        sl.InsertAtHead(value);
    }

    void pop()
    {
        if (sl.size() == 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        sl.DeleteAtHead();
    }

    T top()
    {
        if (sl.size() == 0)
        {
            cout << "Stack is empty ";
            T a;
            return a;
        }
        return sl.head->data;
    }
};

int main()
{
    Stack<int> st;
    st.push(10);
    st.push(50);
    st.push(100);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    return 0;
}