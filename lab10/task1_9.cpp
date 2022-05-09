#include <iostream>

using namespace std;

struct Properties
{
    int tires;
    string size;
    int seats;
    string color;
    string plateNum;
    string model;
};

class Vehicle
{
protected:
    int tires;
    string size;
    int seats;

public:
    Vehicle()
    {
        tires = 0;
        size = "";
        seats = 0;
    }
    ~Vehicle() {}

    virtual void setValues()
    {
        cout << "Tires: ";
        cin >> tires;
        cout << "Size: ";
        cin >> size;
        cout << "Seats: ";
        cin >> seats;
    }

    virtual Properties getValues()
    {
        Properties p;
        p.tires = tires;
        p.size = size;
        p.seats = seats;

        return p;
    }

    void print()
    {
        cout << "Tires: " << tires << "\nSize: " << size << "\nSeats: " << seats;
    }
};

class Car : protected Vehicle
{
protected:
    string color;

public:
    Car() : color("")
    {
        Vehicle();
    }
    ~Car() {}

    virtual void setValues()
    {
        cout << "Tires: ";
        cin >> tires;
        cout << "Size: ";
        cin >> size;
        cout << "Seats: ";
        cin >> seats;
        cout << "Color: ";
        cin >> color;
    }

    virtual Properties getValues()
    {
        Properties p;
        p.tires = tires;
        p.size = size;
        p.seats = seats;
        p.color = color;

        return p;
    }

    void print()
    {
        Vehicle::print();
        cout << "Color: " << color;
    }
};

class Vitz : protected Car
{
protected:
    string plateNum;
    string model;

public:
    Vitz() : plateNum(""), model("")
    {
        Car();
    }
    ~Vitz() {}

    virtual void setValues()
    {
        cout << "Tires: ";
        cin >> tires;
        cout << "Size: ";
        cin >> size;
        cout << "Seats: ";
        cin >> seats;
        cout << "Color: ";
        cin >> color;
        cout << "PlateNum: ";
        cin >> plateNum;
        cout << "Model: ";
        cin >> model;
    }

    virtual Properties getValues()
    {
        Properties p;
        p.tires = tires;
        p.size = size;
        p.seats = seats;
        p.color = color;
        p.plateNum = plateNum;
        p.model = model;

        return p;
    }

    void print()
    {
        Vehicle::print();
        cout << "Plate Number: " << plateNum << "\nModel: " << model;
    }
};

int main()
{
}