#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = (rand() % 100) + 1;
    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have picked a number between 1 and 100. Can you guess it?" << endl;

    // Game loop
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }
    } while (userGuess != randomNumber);

    cout << "Thank you for playing!" << endl;

    return 0;
}
