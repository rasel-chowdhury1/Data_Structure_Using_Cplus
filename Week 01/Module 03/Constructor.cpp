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
    Student(string name, int id, int age, string f_name, string m_name)
    {
        this->name = name;
        this->id = id;
        this->age = age;
        father = f_name;
        mother = m_name;
    }

    Student(string name, string dept, int id){
        this->name = name;
        this->dept = dept;
        this->id = id;
    }

    void print_info()
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "ID: " << id << "\n";
        cout << "Father Name: " << father << "\n";
        cout << "Mother Name: " << mother << "\n";
        cout<<"Department: "<<dept<<"\n";
    }
};
int main()
{
    Student s("Sujan Sarkar",478862,20,"Robel Sarkar","Rabia Akter");
    Student s1("Sujan Sarkar.","CSE",478862);
    s.print_info();
    s1.print_info();
    return 0;
}