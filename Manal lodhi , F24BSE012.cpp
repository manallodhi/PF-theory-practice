
#include <iostream>
using namespace std;

struct Student
{
string name;
int rollNumber;
int marks[3];
};

void addStudent(Student &s)
{
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;
    cout << "Enter Marks for 3 subjects: ";
    for (int i = 0; i < 3; i++) {
    cin >> s.marks[i];
    }
    cout << "Student details added successfully!\n";
}

int calculateTotalMarks(const Student &s)
{
int total = 0;
for (int i = 0; i < 3; i++) {
total = total + s.marks[i];
}
return total;
}

void displayStudent(const Student &s)
{
cout << "\nStudent Details:\n";
cout << "Name: " << s.name << "\n";
cout << "Roll Number: " << s.rollNumber << "\n";
cout << "Marks: ";
for (int i = 0; i < 3; i++) {
cout << s.marks[i] << " ";
}
cout << "\nTotal Marks: " << calculateTotalMarks(s) << "\n";
}

int main()
{
Student s;
addStudent(s);
displayStudent(s);
return 0;
}
