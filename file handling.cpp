
#include <iostream>
#include <fstream> // For file handling
using namespace std;

int main() {
    // Variable to store a single line of text
    string line;
    // Variable to store the entire content of the file
    string text;

    // Open the file in read mode to read its content
    ifstream inputFile("test.txt");

    // Check if the file opened successfully
    if (!inputFile) {
        cout << "Error: Unable to open the file for reading.\n";
        return 1; // Exit the program with an error code
    }

    // Read the file line by line and append to the text variable
    while (getline(inputFile, line)) {
        text += line + '\n'; // Append the line and add a newline character
    }

    // Close the input file
    inputFile.close();

    // Print the existing content of the file
    cout << "File content before adding new text:\n";
    cout << text;

    // Now, open the file in append mode to add new text
    ofstream outputFile("test.txt", ios::app);

    // Check if the file opened successfully
    if (!outputFile) {
        cout << "Error: Unable to open the file for writing.\n";
        return 1; // Exit the program with an error code
    }

    // Get new text from the user
    cout << "\nEnter the text you want to add to the file: ";
    string newText;
    getline(cin, newText); // Read the new text from the user

    // Write the new text to the file
    outputFile << newText << endl;

    // Close the output file
    outputFile.close();

    cout << "Text added to the file successfully!\n";

    return 0;
}

