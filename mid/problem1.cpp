#include <iostream>
#include <cmath>

using namespace std;

#define SHIFT(num1, num2) (num1 ^ (1 << num2))

struct Distance
{
    string cities[5] = {"Topi", "Isl", "Lhr", "Khi", "Rwp"};
    int points[5][2];
    int distance[5][5];
};

void calcDis(Distance &d)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int x = d.points[i][0] - d.points[j][0], y = d.points[i][1] - d.points[j][1];
            d.distance[i][j] = abs(x) + abs(y);
        }
    }
}

void printDis(Distance &d)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << d.distance[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int sh;
    Distance dis;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the number: ";
        cin >> dis.points[i][0];
        cout << "Enter bit to be changed: ";
        cin >> sh;

        dis.points[i][1] = SHIFT(dis.points[i][0], sh);
        cout << dis.points[i][1] << "\n";
    }

    calcDis(dis);
    printDis(dis);
}