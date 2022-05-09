#include <iostream>

using namespace std;

void print(int *n)
{
    cout << "The value of ptr const: ";
    cout << 10 * (*n);
}

int main()
{
    int n = 50;
    const int *nPtr = &n;

    print(const_cast<int *>(nPtr));
}