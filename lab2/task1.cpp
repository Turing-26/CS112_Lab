#include <iostream>

using namespace std;

#define CHECK(num, num2) (num & num2)

int main() {
    int num;

    cout << "Enter the number: ";
    cin >> num;

    int num2 = num-1;

    if (CHECK(num, num2) == 0)
        cout << "Yes, " << num << " is a power of 2";
    else
        cout << "No, " << num << " is not a power of 2";
}