#include <bits/stdc++.h>
using namespace std;
class user
{
private:
    string password;

public:
    string name;

    void pass(string sec)
    {
        password = sec;
    }

protected:
    int age;
};

class Admin : user
{
private:
    string designation;

public:
    void set(string n, int ag, int dg)
    {
        name = n;
        age = ag;
        designation = dg;
    }

    void print()
    {
        cout << name << "\n";
        cout << age << "\n";
        cout << designation << "\n";
    }
};

int main()
{
    Admin ad;
    ad.set("Sujan Sarkar", 20, 100);
    
    ad.print();
}