#include <iostream>

using namespace std;

class Person;

class Date
{
    friend class Person;
    int year;
    int month;
    int date;

public:
    Date() : year(0), month(0), date(0) {}
    ~Date() {}

    friend ostream &operator<<(ostream &COUT, Date &d1)
    {
        COUT << d1.year << "-" << d1.month << "-" << d1.date;
        return COUT;
    }

    friend istream &operator>>(istream &CIN, Date &d1)
    {
        cout << "Enter the date (yyyy mm dd): ";
        CIN >> d1.year >> d1.month >> d1.date;

        if (d1.month < 1 || d1.month > 12)
        {
            cout << "Enter the date (yyyy mm dd): ";
            CIN >> d1.year >> d1.month >> d1.date;
        }
        else if (d1.date < 1 || d1.date > 31)
        {
            cout << "Enter the date (yyyy mm dd): ";
            CIN >> d1.year >> d1.month >> d1.date;
        }
        else if (d1.month == 2 || d1.date > 29)
        {
            cout << "Enter the date (yyyy mm dd): ";
            CIN >> d1.year >> d1.month >> d1.date;
        }
        return CIN;
    }
};

class Person
{
    static int count;
    string name;
    int id;
    Date date;

public:
    Person()
    {
        count++;
    }
    ~Person()
    {
        count--;
    }

    friend ostream &operator<<(ostream &COUT, Person p1)
    {
        COUT << p1.name << ", " << p1.id << " joining " << p1.date;
        return COUT;
    }

    friend istream &operator>>(istream &CIN, Person &p1)
    {
        cout << "Enter name and ID: ";
        CIN >> p1.name >> p1.id;
        CIN >> p1.date;
        return CIN;
    }

    bool operator<(Person p1)
    {
        if (this->date.year < p1.date.year)
            return true;
        else if (this->date.year > p1.date.year)
            return false;
        else if (this->date.year == p1.date.year && this->date.month < p1.date.month)
            return true;
        else if (this->date.year == p1.date.year && this->date.month > p1.date.month)
            return false;
        else if (this->date.year == p1.date.year && this->date.month == p1.date.month && this->date.date < p1.date.date)
            return true;
        else if (this->date.year == p1.date.year && this->date.month == p1.date.month && this->date.date > p1.date.date)
            return false;
        else
            return true;
    }
};

int Person::count = 0;

int main()
{
    Person p1, p2;

    cout << "Person 1" << endl;
    cin >> p1;
    cout << "Person 2" << endl;
    cin >> p2;

    if (p1 < p2)
        cout << p1 << " is senior of " << p2;
    else
        cout << p2 << " is the senior of " << p1;
}