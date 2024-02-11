/*
input: [3,4,6,2,5]

1) if the tmpStack is greater than input stack popped element then we need to pop the element from tmpStack and push onto input stack

2) else push onto tmpStack. 

1st iteration:
Element taken out: 5
input: [3,4,6,2]
tmpStack: [5]

2nd iteration:
Element taken out: 2
input: [3,4,6,5]
tmpStack:[2]

3rd iteration:
Element taken out: 5
input: [3,4,6]
tmpStack:[2,5]

4th iteration:
Element taken out: 6
input: [3,4]
tmpStack: [2,5,6]

5th iteration:
Element taken out: 4
input: [3,6,5]
tmpStack: [2,4]

6th iteration:
Element taken out: 5
input: [3,6]
tmpStack: [2,4,5]

7th iteration:
Element taken out: 6
input: [3]
tmpStack:[2,4,5,6]

8th iteration:
Element taken out: 3
input: [6,5,4]
tmpStack: [2,3]

9th iteration:
Element taken out: 4
input: [6,5]
tmpStack: [2,3,4]

10th iteration:
Element taken out: 5
input: [6]
tmpStack: [2,3,4,5]

11th iteration:
Element taken out: 6
input: []
tmpStack: [2,3,4,5,6]

final stored value is [2,3,4,5,6]
*/

#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;

    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();

        while (!tmpStack.empty() && tmpStack.top() > tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }

    return tmpStack;
}

int main()
{
    stack<int> input;
    input.push(5);
    input.push(2);
    input.push(6);
    input.push(4);
    input.push(3);

    stack<int> tmpStack = sortStack(input);

    while (!tmpStack.empty())
    {
        cout << tmpStack.top() << " ";
        tmpStack.pop();
    }
}
