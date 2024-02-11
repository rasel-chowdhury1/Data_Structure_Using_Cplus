#include <bits/stdc++.h>
using namespace std;

int evaluate(int operand1, int operand2, char op)
{
    if (op == '+')
    {
        return operand1 + operand2;
    }
    else if (op == '-')
    {
        return operand1 - operand2;
    }
    else if (op == '*')
    {
        return operand1 * operand2;
    }
    else if (op == '/')
    {
        return operand1 / operand2;
    }
}

int prec(char ch)
{
    if (ch == '*' || ch == '/')
        return 1;
    else if (ch == '+' || ch == '-')
        return 0;
    return -1;
}

string infixTOpostfix(string s)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        char now = s[i];
        if ((now >= 'a' && now <= 'z') || (now >= '0' && now <= '9'))
        {
            ans += now;
        }
        else if (now == '(')
        {
            st.push('(');
        }
        else if (now == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (st.size() && prec(st.top()) >= prec(now))
            {
                ans += st.top();
                st.pop();
            }
            st.push(now);
        }
    }
    while (st.size())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    stack<int> st;
    string inpos = infixTOpostfix(s);
    for (int i = 0; i < inpos.size(); i++)
    {
        char now = inpos[i];
        if (now >= '0' && now <= '9')
        {
            st.push(now - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int ans = evaluate(op1, op2, now);
            st.push(ans);
        }
    }
    cout << st.top();

    return 0;
}
