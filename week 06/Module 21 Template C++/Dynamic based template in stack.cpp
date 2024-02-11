#include <bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
public:
    T *arr;
    int stack_size;
    int stack_capacity;
    Stack()
    {
        arr = new T[1];
        stack_size = 0;
        stack_capacity = 1;
    }

    void increaseSize()
    {
        T *tmp;
        tmp = new T[stack_capacity * 2];
        for (int i = 0; i < stack_size; i++)
        {
            tmp[i] = arr[i];
        }
        swap(arr, tmp);
        delete[] tmp;
        stack_capacity = stack_capacity * 2;
    }

    void push(T val)
    {
        if (stack_size + 1 > stack_capacity)
        {
            increaseSize();
        }
        stack_size += 1;
        arr[stack_size - 1] = val;
    }

    void pop()
    {
        if (stack_size == 0)
        {
            cout << "Empty Stack!\n";
            return;
        }
        stack_size -= 1;
    }

    T top()
    {
        if (stack_size == 0)
        {
            cout << "Empty Stack ";
            T a;
            return a;
            // assert(false);
        }
        return arr[stack_size - 1];
    }
};
int main()
{
    Stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();

    Stack<double> st1;
    st1.push(1.1);
    st1.push(1.2);
    st1.push(1.3);
    cout << st1.top() << endl;
    st1.pop();
    cout << st1.top() << endl;
    st1.pop();
    cout << st1.top() << endl;
    st1.pop();

    Stack<char> st2;
    st2.push('n');
    st2.push('a');
    st2.push('j');
    st2.push('u');
    st2.push('S');
    cout << st2.top() << endl;
    st2.pop();
    cout << st2.top() << endl;
    st2.pop();
    cout << st2.top() << endl;
    st2.pop();
    cout << st2.top() << endl;
    st2.pop();
    cout << st2.top() << endl;
    st2.pop();
}