#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if((long long int)dividend/divisor>pow(2,31)-1) return pow(2,31)-1;
        if((long long int)dividend/divisor<(-1)*pow(2,31)) return (-1)*pow(2,31);
        return dividend/divisor;
    }
};
int main()
{
    Solution h;
    int dividend, divisor;
    cin >> dividend >> divisor;
    int ans = h.divide(dividend, divisor);
    cout << ans << endl;
}