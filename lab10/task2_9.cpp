#include <iostream>

using namespace std;

struct Features
{
    string name;
    string eyeColor;
    string hairColor;
    string education;
    int age;
};

class Parent
{
protected:
    string name;
    string eyeColor;
    string hairColor;

public:
    Parent()
    {
        cout << "Name: ";
        cin >> name;
        cout << "Eye color: ";
        cin >> eyeColor;
        cout << "Hair color: ";
        cin >> hairColor;
    };
    ~Parent(){};

    virtual Features get()
    {
        Features f;
        f.name = name;
        f.eyeColor = eyeColor;
        f.hairColor = hairColor;
    }

    virtual void set()
    {
        cout << "Name: ";
        cin >> name;
        cout << "Eye Color: ";
        cin >> eyeColor;
        cout << "Hair Color: ";
        cin >> hairColor;
    }
};

class Child : protected Parent
{
    string ed;
    int age;

public:
    Child()
    {
        Parent();
        cout << "Education: ";
        cin >> ed;
        cout << "Age: ";
        cin >> age;
    };
    ~Child(){};

    virtual Features get()
    {
        Features f;
        f.name = name;
        f.eyeColor = eyeColor;
        f.hairColor = hairColor;
        f.education = ed;
        f.age = age;
    }

    virtual void set()
    {
        cout << "Name: ";
        cin >> name;
        cout << "Eye Color: ";
        cin >> eyeColor;
        cout << "Hair Color: ";
        cin >> hairColor;
        cout << "Education: ";
        cin >> ed;
        cout << "Age: ";
        cin >> age;
    }
};

int main()
{
    Parent myFather, myMother;
    Child myself, mySister;
}