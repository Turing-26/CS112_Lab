#include <iostream>

using namespace std;

class SecOfficer;

class Officer
{
    friend class SecOfficer;
    string name;
    int id;
    string rank;
    static int count;

public:
    Officer() : name(""), id(0), rank("") {}
    void setOfficer()
    {
        cout << "Enter the officer name: ";
        cin >> name;
        while (1)
        {
            cout << "Enter the officer id: ";
            cin >> id;

            if (cin.fail())
            {
                cout << "Invalid id, enter again...\n";
            }
            else
                break;
        }
        cout << "Enter the officer rank: ";
        cin >> rank;

        count++;
    }
    static int getCount()
    {
        return count;
    }
};

class SecOfficer
{

public:
    void checkOfficer(Officer o1)
    {
        if (o1.id == 0)
        {
            cout << "No officer has entered the area\n";
            return;
        }

        int id = o1.id, rev = 0, digit;

        while (id != 0)
        {
            digit = id % 10;
            rev = (rev * 10) + digit;
            id /= 10;
        }

        if (rev == o1.id)
        {
            cout << "The officer is not allowed to enter the area.\n";
        }
        else
            cout << "This officer can enter the area.\n";
    }
};

int Officer::count = 0;

int main()
{
    Officer o1;
    SecOfficer so1;
    int choice;

    while (1)
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Please select the desired option: " << endl;
        cout << "1. Enter id of officer " << endl;
        cout << "2. Get total number of officers" << endl;
        cout << "3. Exit" << endl;
        cout << "-------------------------------------------------------------------" << endl;

        cout << "Enter the option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            o1.setOfficer();
            so1.checkOfficer(o1);
            break;
        case 2:
            cout << "Total number of officers are: " << o1.getCount() << endl;
            break;
        case 3:
            break;
        default:
            cout << "Incorrect option, try again....";
        }

        if (cin.fail())
        {
            cin.ignore();
        }
        if (choice == 3)
            break;
    }
}