#include <bits/stdc++.h>
using namespace std;
class Persion
{
public:
    string name;
    Persion *father, *mother;
    void print_info()
    {
        cout << "Name: " << name << "\n";
        cout << "Father Name: " << father->name << "\n";
        cout << "Mother Name: " << mother->name << "\n";
    }
};
int main()
{
    Persion p;
    p.father = new Persion;
    p.mother = new Persion;
    cout<<"Your Name: ";
    p.name;
    getline(cin, p.name);
    cout<<"Your father's Name: ";
    p.father->name;
    getline(cin, p.father->name);
    cout<<"Your mother's Name: ";
    p.mother->name;
    getline(cin, p.mother->name);

    p.print_info();
}