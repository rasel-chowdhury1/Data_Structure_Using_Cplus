#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int id;
    int age;
    string father, mother;
    string dept;
    Student()
    {
    }

    Student(string name, int age, int id)
    {
        this->name = name;
        this->age = age;
        this->id = id;
    }

    void print_info()
    {
        cout << name << " " << age << " " << id << "\n";
    }
};
int main()
{
    Student s[10];
    for (int i = 0; i < 10; i++)
    {
        s[i] = Student("Sujan", 20, i + 1);
    }
    for (int i = 0; i < 10; i++)
    {
        s[i].print_info();
    }

    return 0;
}