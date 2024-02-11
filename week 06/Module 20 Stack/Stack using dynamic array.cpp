#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *a;
    int array_cap;
    int Stack_size;
    Stack()
    {
        a = new int[1];
        array_cap = 1;
        Stack_size = 0;
    }

    void increase_size()
    {
        int *tmp;
        tmp = new int[array_cap * 2];
        for (int i = 0; i < array_cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        delete[] tmp;
        array_cap = array_cap * 2;
    }

    void push(int val)
    {
        if (Stack_size + 1 > array_cap)
        {
            increase_size();
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
            cout << "Stack is empty ";
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
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
}