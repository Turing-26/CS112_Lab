#include <iostream>

using namespace std;

int main()
{
    double l, w;

    cout << "Enter the length of the rectangle: ";
    cin >> l;

    cout << "Enter the width of the rectangle: ";
    cin >> w;

    int temp = (int)l * w;

    cout << "INT" << endl
         << "The area of the rectangle is " << temp << endl;

    cout << "FLOAT" << endl
         << "The area of the rectangle is " << float(l * w) << endl;
}