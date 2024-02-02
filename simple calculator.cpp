#include <iostream>
using namespace std;

template <typename T>
T calculate(T num1, T num2, char operation) {
    switch (operation) {
    case '-':
        return num1 - num2;
    case '+':
        return num1 + num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0) {
            return num1 / num2;
        }
        else {
            cout << "error: cannot divide by zero." <<  endl;
            return 0;
        }
    default:
         cout<< "invalid operation. please choose +, -, *, or /." <<  endl;
        return 0;
    }
}

int main1() {
    double num1, num2, result;
    char sign;
     cout << "enter first number: ";
     cin >> num1;
     cout << "enter second number: ";
     cin >> num2;
     cout << "ehoose sign (+, -, *, /): ";
     cin >> sign;
      result = calculate(num1, num2, sign);
     cout << "Result: " << result <<  endl;
    return 0;
}
