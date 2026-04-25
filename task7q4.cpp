#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e)
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() {
        cout << "Name: " << name << " | ID: " << id
             << " | Phone: " << phoneNumber << " | Email: " << email << endl;
    }
    void updateInfo(string phone, string mail) {
        phoneNumber = phone; email = mail;
        cout << "Info updated." << endl;
    }
};

class Student : public Person {
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e,
            string courses, double gpa, int year)
        : Person(n, i, a, p, e), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override {
        cout << "[Student] ";
        Person::displayInfo();
        cout << "  Courses: " << coursesEnrolled
             << " | GPA: " << GPA
             << " | Enrolled: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
    string department, coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e,
              string dept, string courses, double sal)
        : Person(n, i, a, p, e), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() override {
        cout << "[Professor] ";
        Person::displayInfo();
        cout << "  Dept: " << department
             << " | Courses: " << coursesTaught
             << " | Salary: $" << salary << endl;
    }
};

class Staff : public Person {
    string department, position;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e,
          string dept, string pos, double sal)
        : Person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        cout << "[Staff] ";
        Person::displayInfo();
        cout << "  Dept: " << department
             << " | Position: " << position
             << " | Salary: $" << salary << endl;
    }
};

int main() {
    Person* people[3];
    people[0] = new Student("Ali",    "S101", "Karachi", "0300-1111", "ali@uni.edu",
                             "OOP, DS", 3.7, 2023);
    people[1] = new Professor("Dr. Sara", "P201", "Lahore", "0300-2222", "sara@uni.edu",
                               "CS Dept", "OOP, AI", 150000);
    people[2] = new Staff("Umar",    "ST301", "Islamabad", "0300-3333", "umar@uni.edu",
                           "Admin", "Coordinator", 80000);

    for (int i = 0; i < 3; i++) {
        people[i]->displayInfo();
        cout << endl;
    }

    for (int i = 0; i < 3; i++) delete people[i];
    return 0;
}