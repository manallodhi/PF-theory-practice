#include <iostream>
using namespace std;
#include <string>

using namespace std;

int main() {
    string studentName;
    int totalMarks = 0, marksObtained = 0;
    double percentage = 0.0;

    // Asking for the student's name
    cout << "Enter the student's name: ";
    getline(cin, studentName);

    // Asking for total marks
    cout << "Enter the total marks: ";
    cin >> totalMarks;

    // Asking for marks obtained
    cout << "Enter the marks obtained: ";
    cin >> marksObtained;

    // Calculating percentage
    if (totalMarks > 0) {
        percentage = (marksObtained * 100.0) / totalMarks;

        // Displaying the result
        cout << "\nStudent Name: " << studentName << endl;
        cout << "Percentage: " << percentage << "%\n";

        // Assigning grades based on percentage
        if (percentage >= 90) {
            cout << "Grade: A\n";
        } else if (percentage >= 75) {
            cout << "Grade: B\n";
        } else if (percentage >= 50) {
            cout << "Grade: C\n";
        } else {
            cout << "Grade: F\n";
        }
    } else {
        cout << "Invalid total marks. Cannot calculate percentage.\n";
    }

    return 0;
}
