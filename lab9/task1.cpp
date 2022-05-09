#include <iostream>

using namespace std;

int main()
{
    int f, s, t;
    char fr, ff;

    cout << "Enter first variable: ";
    cin >> f;

    cout << "Enter third variable: ";
    cin >> t;

    cout << "Enter fourth variable: ";
    cin >> fr;

    cout << "Enter fifth variable: ";
    cin >> ff;

    s = f;

    float r = t + ff;

    cout << "First variable: " << f << endl;
    cout << "Second variable: " << s << endl;
    cout << "type casting char to int (third + fourth): " << t + fr << endl;
    cout << "type casting int to float (third + fifth): " << r << endl;
}