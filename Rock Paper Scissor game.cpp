#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

int main() {
    char playerChoice, computerChoice;
    string options[3] = {"R", "P", "S"}; // R for Rock, P for Paper, S for Scissors

    // Seed the random number generator
    srand(time(0));
    computerChoice = options[rand() % 3][0]; // Randomly select 'R', 'P', or 'S'

    cout << "Welcome to Rock-Paper-Scissors!" << endl;
    cout << "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
    cin >> playerChoice;

    // Convert player input to uppercase for consistency
    playerChoice = toupper(playerChoice);

    cout << "\nYou chose: " << playerChoice << endl;
    cout << "Computer chose: " << computerChoice << endl;

    // Game logic
    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == 'P' && computerChoice == 'R') ||
               (playerChoice == 'S' && computerChoice == 'P') ||
               (playerChoice == 'R' && computerChoice == 'S')) {
        cout << "You win!" << endl;
    } else if ((playerChoice == 'R' || playerChoice == 'P' || playerChoice == 'S')) {
        cout << "You lose!" << endl;
    } else {
        cout << "Invalid choice! Please choose R, P, or S next time." << endl;
    }

    return 0;
}
