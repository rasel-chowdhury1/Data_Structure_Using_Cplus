#include <bits/stdc++.h>
using namespace std;

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
    string ans = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char now = s[i];
        if (now >= 'a' && now <= 'z')
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
    string ans = infixTOpostfix(s);
    cout << ans << endl;
    return 0;
}
