#include <iostream>

using namespace std;

int main()
{
    int size, high, low;

    cout << "Enter the size: ";

    while (1)
    {
        if (cin >> size)
            break;
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid size, enter again: ";
        }
    }

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    high = arr[0];
    low = high;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > high)
            high = arr[i];

        if (arr[i] < low)
            low = arr[i];
    }

    int *temp = new int[size - 2];

    int i = 0,
        j = 0;
    while (1)
    {
        if (arr[j] != high && arr[j] != low)
        {
            temp[i] = arr[j];
            i++;
            j++;
        }
        else
            j++;
        if (i == size - 2)
            break;
    }
    delete[] arr;

    high = temp[0];
    low = high;

    for (int i = 0; i < size - 2; i++)
    {
        if (temp[i] > high)
            high = temp[i];

        if (temp[i] < low)
            low = temp[i];
    }
    delete[] temp;

    cout
        << "Second highest: " << high << endl
        << "Second lowest: " << low;
}