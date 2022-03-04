#include <iostream>

using namespace std;

#define POW(num1, num2) (num1 * (2 << (num2-1)))

int main() {
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    if (num2 == 0)
        cout << "The answer is: " << num1;
    else {
        while (num2 < 0) {
            cout << "Invalid power input, please enter again: ";
            cin >> num2;
        }

        cout << "The answer is: " << POW(num1, num2);
    }
}