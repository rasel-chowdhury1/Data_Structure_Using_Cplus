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
    // Way: 01->Operation overload:
    //  bool operator<(Student s)
    //  {
    //      return id < s.id;
    //  }
};

bool comp(Student a, Student b)
{
    // Way 2:
    return a.id < b.id;
}

int main()
{
    vector<Student> a;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(Student("Sujan", 20, 20 - i));
    }
    for (int i = 0; i < 5; i++)
    {
        a[i].print_info();
    }

    cout << "After Sort:\n";
    sort(a.begin(), a.end(), comp);

    for (int i = 0; i < 5; i++)
    {
        a[i].print_info();
    }

    return 0;
}