#include <iostream>
#include <fstream> // For file handling
#include <cstring> // For string comparison (strcmp function)
using namespace std;

// Structure to store student details
struct Student {
    char name[50];
    char id[20];
    char department[50];
};

// Global array to store students
Student students[100];
int studentCount = 0; // Keeps track of the number of students

// Function to load students from the file
void loadStudentsFromFile() {
    ifstream inFile("students.txt"); // Open the file in text mode
    if (inFile) {
        studentCount = 0; // Reset the student count
        while (inFile.getline(students[studentCount].name, 50)) {
            inFile.getline(students[studentCount].id, 20);
            inFile.getline(students[studentCount].department, 50);
            studentCount++;
        }
        inFile.close();
    }
}

// Function to save students to the file
void saveStudentsToFile() {
    ofstream outFile("students.txt"); // Open the file in text mode
    for (int i = 0; i < studentCount; i++) {
        outFile << students[i].name << endl;
        outFile << students[i].id << endl;
        outFile << students[i].department << endl;
    }
    outFile.close();
}

// Function to add a new student
void addStudent() {
    if (studentCount >= 100) {
        cout << "Error: Maximum student limit reached.\n";
        return;
    }

    Student newStudent;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(newStudent.name, 50);
    cout << "Enter ID: ";
    cin.getline(newStudent.id, 20);
    cout << "Enter Department: ";
    cin.getline(newStudent.department, 50);

    students[studentCount] = newStudent;
    studentCount++;
    saveStudentsToFile(); // Save the updated data to the file
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayAllStudents() {
    if (studentCount == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "Name: " << students[i].name
             << ", ID: " << students[i].id
             << ", Department: " << students[i].department << endl;
    }
}

// Function to search for a student by ID
void searchStudentByID() {
    if (studentCount == 0) {
        cout << "No students to search.\n";
        return;
    }

    char queryID[20];
    cout << "Enter ID to search: ";
    cin.ignore();
    cin.getline(queryID, 20);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, queryID) == 0) {
            cout << "\n--- Student Found ---\n";
            cout << "Name: " << students[i].name
                 << ", ID: " << students[i].id
                 << ", Department: " << students[i].department << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found!\n";
    }
}

// Function to update student information
void updateStudent() {
    if (studentCount == 0) {
        cout << "No students to update.\n";
        return;
    }

    char queryID[20];
    cout << "Enter ID to update: ";
    cin.ignore();
    cin.getline(queryID, 20);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, queryID) == 0) {
            cout << "\n--- Update Student ---\n";
            cout << "Enter new Name: ";
            cin.getline(students[i].name, 50);
            cout << "Enter new Department: ";
            cin.getline(students[i].department, 50);
            saveStudentsToFile(); // Save the updated data to the file
            cout << "Student information updated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found!\n";
    }
}

// Function to delete a student
void deleteStudent() {
    if (studentCount == 0) {
        cout << "No students to delete.\n";
        return;
    }

    char queryID[20];
    cout << "Enter ID to delete: ";
    cin.ignore();
    cin.getline(queryID, 20);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, queryID) == 0) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            saveStudentsToFile(); // Save the updated data to the file
            cout << "Student deleted successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found!\n";
    }
}

// Main function to display the menu and handle user input
int main() {
    loadStudentsFromFile(); // Load existing data from the file
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search for a Student by ID\n";
        cout << "4. Update Student Information\n";
        cout << "5. Delete a Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudentByID();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
