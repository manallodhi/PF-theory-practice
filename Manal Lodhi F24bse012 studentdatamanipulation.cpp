#include <iostream>
#include <cstring> // For string comparison (strcmp function)
using namespace std;

// Structure to store student details
struct Student {
    char name[50];       // Student's name
    char id[20];         // Student's unique ID
    char department[50]; // Student's department
};

// Global array to store students
Student students[100]; // Maximum capacity of 100 students
int studentCount = 0;  // Keeps track of the number of students

// Function to add a new student
void addStudent() {
    if (studentCount >= 100) {
        // Check if the maximum student capacity has been reached
        cout << "Error: Maximum student limit reached.\n";
        return;
    }

    // Input details of the new student
    Student newStudent;
    cout << "Enter Name: ";
    cin.ignore(); // Clear input buffer
    cin.getline(newStudent.name, 50); // Read name
    cout << "Enter ID: ";
    cin.getline(newStudent.id, 20); // Read ID
    cout << "Enter Department: ";
    cin.getline(newStudent.department, 50); // Read department

    // Add the new student to the array
    students[studentCount] = newStudent;
    studentCount++; // Increment the student count

    cout << "Student added successfully!\n";
}

// Function to display all students
void displayAllStudents() {
    if (studentCount == 0) {
        // Check if there are no students to display
        cout << "No students to display.\n";
        return;
    }

    // Loop through all students and print their details
    cout << "\n--- Student List ---\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "Name: " << students[i].name
             << ", ID: " << students[i].id
             << ", Department: " << students[i].department << endl;
    }
}

// Function to search for a student by their unique ID
void searchStudentByID() {
    if (studentCount == 0) {
        // Check if there are no students to search
        cout << "No students to search.\n";
        return;
    }

    char queryID[20]; // ID to search for
    cout << "Enter ID to search: ";
    cin.ignore(); // Clear input buffer
    cin.getline(queryID, 20); // Read the ID to search

    // Loop through all students to find a matching ID
    bool found = false; // Flag to check if student is found
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, queryID) == 0) {
            // If a match is found, print the student's details
            cout << "\n--- Student Found ---\n";
            cout << "Name: " << students[i].name
                 << ", ID: " << students[i].id
                 << ", Department: " << students[i].department << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        // If no match is found, display an appropriate message
        cout << "Student not found!\n";
    }
}

// Function to update an existing student's details
void updateStudent() {
    if (studentCount == 0) {
        // Check if there are no students to update
        cout << "No students to update.\n";
        return;
    }

    char queryID[20]; // ID to search for
    cout << "Enter ID to update: ";
    cin.ignore(); // Clear input buffer
    cin.getline(queryID, 20); // Read the ID to search

    // Loop through all students to find a matching ID
    bool found = false; // Flag to check if student is found
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, queryID) == 0) {
            // If a match is found, prompt for new details
            cout << "\n--- Update Student ---\n";
            cout << "Enter new Name: ";
            cin.getline(students[i].name, 50); // Update name
            cout << "Enter new Department: ";
            cin.getline(students[i].department, 50); // Update department
            cout << "Student information updated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        // If no match is found, display an appropriate message
        cout << "Student not found!\n";
    }
}

// Function to delete a student by their unique ID
void deleteStudent() {
    if (studentCount == 0) {
        // Check if there are no students to delete
        cout << "No students to delete.\n";
        return;
    }

    char queryID[20]; // ID to search for
    cout << "Enter ID to delete: ";
    cin.ignore(); // Clear input buffer
    cin.getline(queryID, 20); // Read the ID to search

    // Loop through all students to find a matching ID
    bool found = false; // Flag to check if student is found
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, queryID) == 0) {
            // If a match is found, remove the student from the array
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1]; // Shift elements to fill the gap
            }
            studentCount--; // Decrement the student count
            cout << "Student deleted successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        // If no match is found, display an appropriate message
        cout << "Student not found!\n";
    }
}

// Main function to display the menu and handle user input
int main() {
    int choice; // User's menu choice
    do {
        // Display the menu
        cout << "\n--- Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search for a Student by ID\n";
        cout << "4. Update Student Information\n";
        cout << "5. Delete a Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle the user's menu choice
        switch (choice) {
            case 1:
                addStudent(); // Add a new student
                break;
            case 2:
                displayAllStudents(); // Display all students
                break;
            case 3:
                searchStudentByID(); // Search for a student by ID
                break;
            case 4:
                updateStudent(); // Update an existing student's details
                break;
            case 5:
                deleteStudent(); // Delete a student by ID
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n"; // Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again.\n"; // Invalid input
        }
    } while (choice != 6); // Repeat until the user chooses to exit

    return 0;
}
