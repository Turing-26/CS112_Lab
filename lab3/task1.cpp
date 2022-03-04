#include <iostream>

using namespace std;

int main()
{
    int size;

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
    int *res = new int[size - 1];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < size - 1; i++)
        res[i] = arr[i + 1] - arr[i];

    delete[] arr;

    cout << "Resultant array: [ ";
    for (int i = 0; i < size - 1; i++)
        cout << res[i] << " ";
    cout << " ]";

    delete[] res;
}