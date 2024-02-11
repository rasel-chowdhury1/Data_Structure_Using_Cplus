#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int std_id;
    string dept;
    int age;
    void Print_Info()
    {
        cout << name << "\n"
             << std_id << "\n"
             << age << "\n"
             << dept << "\n";
    }
};

class Circle
{
public:
    int radius;
    float circle_are()
    {
        return 0.5 * 3.1416 * radius;
    }
};

int main()
{
    Student s;
    s.name = "Sujan Sarkar.";
    s.age = 20;
    s.std_id = 478862;
    s.dept = "CSE";
    s.Print_Info();

    Circle a1;
    a1.radius;
    cin >> a1.radius;
    cout << a1.circle_are();

    return 0;
}