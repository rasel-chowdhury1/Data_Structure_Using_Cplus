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
        if (now == '{')
        {
            st.push(now);
        }
        else if (now == '}')
        {
            if (st.empty() || st.top() != '{')
            {
                cout << "0\n";
                return 0;
            }
            if (now == '}' && st.top() == '{')
            {
                st.pop();
            }
        }
    }
    if (st.empty())
    {
        cout << s.size() << "\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}
