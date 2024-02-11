#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    // string s1 = " Sarkar.";
    // string s2 = s + s1;
    // cout << s2 << endl;
    // cout << s.size(); /*size check*/


    s.pop_back();
    s.erase(s.begin());
    cout << s << endl;

    return 0;
}