#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int std_id;
    int age;
    Student(string name, int id, int age)
    {
        this->name = name;
        std_id = id;
        this->age = age;
    }
    void student_info()
    {
        cout << "NAME: " << name << "\n";
        cout << "ID: " << std_id << "\n";
        cout << "AGE: " << age << "\n";
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Student *s = new Student("Sujan Sarkar", 478862, 20);
    // Pointer object ke access kora jay dui bhabe: 1) (*s).name; 2)s->name;
    (*s).student_info(); // 1
    s->student_info();   // 2
}