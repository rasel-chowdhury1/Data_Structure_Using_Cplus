#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    st.push(12);
    st.push(9);
    st.push(6);

    cout << "Stack size: " << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << "Stack size: " << st.size() << endl;
    
}