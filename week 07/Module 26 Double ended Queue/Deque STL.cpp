#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_back(5);
    dq.push_back(15);
    dq.push_back(25);
    dq.pop_back();
    dq.pop_front();
    cout << "Deque size: " << dq.size() << "\n";
    cout << "Front: " << dq.front() << " Back: " << dq.back() << "\n";
}