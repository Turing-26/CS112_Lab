#include <iostream>

using namespace std;

class Heater
{
private:
    int temp;

public:
    Heater() : temp(15)
    {
        cout << "Temperature = " << temp << endl;
    }
    ~Heater() {}

    void warmer()
    {
        temp += 5;
        cout << "Temperature = " << temp << endl;
    }

    void cooler()
    {
        temp -= 5;
        cout << "Temperature = " << temp << endl;
    }
};

int main()
{
    int choice;
    Heater h;

    while (1)
    {
        cout << "----------------------------------------------\n";
        cout << "1. To increase temperature\n";
        cout << "2. To decrease temperature\n";
        cout << "----------------------------------------------\n";
        cout << "Enter option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            h.warmer();
            break;
        case 2:
            h.cooler();
            break;
        }
        if (choice != 1 && choice != 2)
            break;
    }
}