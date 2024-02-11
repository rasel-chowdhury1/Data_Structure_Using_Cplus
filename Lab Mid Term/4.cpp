#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int first_idx, int last_idx)
{
    if (first_idx >= last_idx)
    {
        return true;
    }

    if (s[first_idx] != s[last_idx])
    {
        return false;
    }

    return isPalindrome(s, first_idx + 1, last_idx - 1);
}

int main()
{
    string s;
    cin >> s;

    if (isPalindrome(s, 0, s.length() - 1) == true)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
