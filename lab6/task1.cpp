#include <iostream>

using namespace std;

class Coordinator;

class Person
{
    friend class Coordinator;
    string comp;
    string uni;

public:
    Person() : comp(""), uni("") {}
};

class Coordinator
{
    Person p1;
    Person p2;

public:
    Coordinator() {}
    void setPersons()
    {
        string ans;
        cout << "Enter competition and university name: ";
        getline(cin >> ws, ans);

        int i = 0;
        while (ans[i] != ' ')
        {
            p1.comp += ans[i];
            i++;
        }
        i++;
        while (ans[i] != '\0')
        {
            p1.uni += ans[i];
            i++;
        }

        cout << "Enter competition and university name: ";
        getline(cin, ans);

        i = 0;
        while (ans[i] != ' ')
        {
            p2.comp += ans[i];
            i++;
        }
        i++;
        while (ans[i] != '\0')
        {
            p2.uni += ans[i];
            i++;
        }
    }

    int giveRoom()
    {
        if (p1.uni == p2.uni)
        {
            int r = 0, i = 0, j = 0;

            while (1)
            {
                if (p1.comp[i] != '\0')
                    i++;
                if (p2.comp[j] != '\0')
                    j++;

                if (p1.comp[i] == '\0' && p2.comp[j] == '\0')
                    break;
            }

            if (j < i)
                return i;
            return j;
        }
        else
            return 0;
    }
};

int main()
{
    Coordinator cood;

    cood.setPersons();

    int room = cood.giveRoom();

    if (room > 0)
    {
        cout << "Person1 and Person2 are roommates and have room number " << room << ".";
    }
    else
        cout << "Person1 and Person2 are not roommates.";
}