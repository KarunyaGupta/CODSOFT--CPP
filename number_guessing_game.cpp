#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;

    int guess;
    bool guessed = false;

    while (!guessed) {
        // Ask the user to guess the number
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;

        // Check if the guess is correct
        if (guess == numberToGuess) {
            cout << " Congratulations! You guessed the correct number.\n";
            guessed = true;
        } else if (guess < numberToGuess) {
            cout << "Your guess is too low. Try again!\n";
        } else {
            cout << "Your guess is too high. Try again!\n";
        }
    }

    return 0;
}


