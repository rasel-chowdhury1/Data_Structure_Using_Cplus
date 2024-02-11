#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    s = " " + s + " ";
    size_t pos = s.find(" Ratul ");

    if (pos != string::npos)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}