#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;
class Stack
{
public:
    int a[MAX_SIZE];
    int Stack_size;
    Stack()
    {
        Stack_size = 0;
    }

    void push(int val)
    {
        if (Stack_size + 1 > MAX_SIZE)
        {
            cout << "Stack is full.\n";
            return;
        }
        Stack_size = Stack_size + 1;
        a[Stack_size - 1] = val;
    }

    void pop()
    {
        if (Stack_size == 0)
        {
            cout << "Stack is empty.\n";
            return;
        }
        a[Stack_size - 1] = 0;
        Stack_size = Stack_size - 1;
    }

    int top()
    {
        if (Stack_size == 0)
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        return a[Stack_size - 1];
    }
};

int main()
{
    Stack st;
    st.push(5);
    cout << st.top() << endl;
    st.push(4);
    cout << st.top() << endl;
    st.push(3);
    cout << st.top() << endl;
    st.push(2);
    cout << st.top() << endl;
    st.push(1);
    st.pop();
    cout << st.top() << endl;
    
}