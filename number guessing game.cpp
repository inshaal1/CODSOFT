#include <iostream>
using namespace std;
int main() {
    int user_guess=0;
    srand(time(0));
    int attempt = 0;
    int secret_number = rand() % 100 + 1;
    cout << "Welcome to Number Guessing Game\n";
    do {
        cout << "enter your guess:";
        cin >> user_guess;
        attempt=attempt+1;
        if (user_guess == secret_number) {
            cout << "congratulation! you have guessed the correct number in " << attempt << " attempts\n";
        }
        else if (user_guess > secret_number) {
            cout << "too high. try again.\n";
        }
        else {
            cout << "too low. try again.\n";
        }
    } while (user_guess != secret_number);
    return 0;
}
