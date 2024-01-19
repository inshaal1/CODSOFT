#include <iostream>
using namespace std;
int main() {
    int userGuess, attempts = 0;
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    cout << "Welcome to Number Guessing Game\n";
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;
        if (userGuess == secretNumber) {
            cout << "CongratS! You guessed the correct number in " << attempts << " attempts.\n";
        }
        else if (userGuess < secretNumber) {
            cout << "Too low! Try again.\n";
        }
        else {
            cout << "Too high! Try again.\n";
        }
    } while (userGuess != secretNumber);
    return 0;
}
