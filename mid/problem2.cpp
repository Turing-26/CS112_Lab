#include <iostream>

using namespace std;

class Officer
{
    static int count;
    int id;
    string name;
    string rank;
    string status;

public:
    Officer()
    {
    }
    ~Officer()
    {
    }
    void setOff()
    {
        cout << "Enter name and ID: ";
        cin >> name >> id;
        cout << "Enter rank: ";
        cin >> rank;
    }
    void showCount()
    {
        cout << "The number of officers allowed are " << count << endl;
    }
    friend bool checkOff(Officer &o, int idInt = 0)
    {
        int sq, temp, res = 0;
        if (idInt == 0)
        {
            sq = o.id * o.id;
        }
        else
        {
            sq = idInt * idInt;
        }

        while (sq > 0)
        {
            temp = sq % 10;
            res = res + temp;
            sq = sq / 10;
        }

        if (res % 2 == 0)
        {
            o.count += 1;
            return 1;
        }
        else
            return 0;
    }
};

int Officer::count = 0;

int main()
{
    int choice;
    Officer o;

    while (1)
    {
        cout << "----------------------------------------------\n";
        cout << "1. To set values\n";
        cout << "2. To print all strings\n";
        cout << "3. To find maximum lnegth\n";
        cout << "4. To compare 2 strings\n";
        cout << "----------------------------------------------\n";
        cout << "Enter option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            o.setOff();
            if (checkOff(o))
            {
                cout << "Allowed\n";
            }
            else
            {
                cout << "Not Allowed\n";
            }
            break;
        case 2:
            o.showCount();
            break;
        case 3:
            int idCh;
            cout << "Enter id to check";
            cin >> idCh;
            if (checkOff(o, idCh))
            {
                cout << "Allowed\n";
            }
            else
            {
                cout << "Not Allowed\n";
            }
            break;
        }
        if (choice == 4)
            break;
    }
}