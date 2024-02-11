#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char now = s[i];
        if (now == '(' || now == '{' || now == '[')
        {
            st.push(now);
        }
        else
        {
            if (st.empty())
            {
                cout << "Invalid\n";
                return 0;
            }
            else if (now == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if (now == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if (now == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                cout << "Invalid\n";
                return 0;
            }
        }
    }
    if (st.empty())
    {
        cout << "Valid\n";
    }
    else
    {
        cout << "Invalid\n";
    }
    return 0;
}

/*
(([][]{()}))

step 1: take input the given string (([][]{()}))
step 2: first character is '(' so it will be push in stack and ith value increament.
step 3: second character is '(' so it will be push in stack and ith value increament.
step 5: third character is '[' so it will be push in stack and ith value increament.
step 5: 4th character is ']' so, now = ']' and stack top is '[' then we need to stack pop so that we can check full code and ith value increament.
step 6: 5th character is '[' so it will be push in stack and ith value increament.
step 7: 6th character is ']' so, now = ']' and stack top is '[' then we need to stack pop so that we can check full code and ith value increament.
step 8: 7th character is '{' so it will be push in stack and ith value increament.
step 10: 8th character is '(' so it will be push in stack and ith value increament.
step 11: 9th character is ')' so, now = ')' and stack top is '(' then we need to stack pop so that we can check full code and ith value increament.
step 12: 10th character is '}' so, now = '}' and stack top is '{' then we need to stack pop so that we can check full code and ith value increament.
step 13: 11th character is ')' so, now = ')' and stack top is '(' then we need to stack pop so that we can check full code and ith value increament.
step 14: 12th character is ')' so, now = ')' and stack top is '(' then we need to stack pop so that we can check full code and ith value increament.
step 15: Stack is empty.

*/