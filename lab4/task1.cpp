#include <iostream>

using namespace std;

class Swap
{
private:
    int A;
    int B;

public:
    void setter()
    {
        cout << "Enter value of A: ";
        cin >> A;
        cout << "Enter value of B: ";
        cin >> B;
    }

    void swapInt()
    {
        A = A * B;
        B = A / B;
        A = A / B;
    }

    void display()
    {
        cout << "A: " << A << endl;
        cout << "B: " << B;
    }
};

int main()
{
    Swap sw;
    sw.setter();
    sw.swapInt();
    sw.display();
}