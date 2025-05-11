#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    
    srand(time(0));

    
    int targetNumber = rand() % 10 + 1;
    int guess = 0;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Guess a number between 1 and 10:\n";

    while (guess != targetNumber) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < targetNumber) {
            cout << "Too low! Try again.\n";
        } else if (guess > targetNumber) {
            cout << "Too high! Try again.\n";
        }
    }

    cout << "Congratulations! You guessed the correct number.\n";
    cout << "It took you " << attempts << " attempts.\n";

    return 0;
}
