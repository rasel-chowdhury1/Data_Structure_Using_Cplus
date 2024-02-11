#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    Person *father, *mother;
    Person()
    {
        father = NULL;
        mother = NULL;
    }

    Person(string name, string f_name, string m_name)
    {
        this->name = name;
        father = new Person;
        father->name = f_name;
        mother = new Person;
        mother->name = m_name;
    }
    void print_info()
    {
        cout << "Name = " << name << "\n";
        cout << "Fathers Name = " << father->name << "\n";
        cout << "Mothers Name = " << mother->name << "\n";
    }

    ~Person()
    {
        cout << "Destructor Executed\n";
        if (father != NULL)
            delete father;
        if (mother != NULL)
            delete mother;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Person p("S", "R", "R");
    p.print_info();
}