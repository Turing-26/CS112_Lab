#include <iostream>

using namespace std;

int main()
{
    int f, s;

    cout << "Enter first value: ";
    cin >> f;

    cout << "Enter second value: ";
    cin >> s;

    float res = f / s;

    cout << "Implicit type casting:-" << endl;
    cout << "Result: " << res << endl;

    cout << "Exlplicit type casting:-" << endl;
    cout << "Result: " << (float)f / s << endl;
}