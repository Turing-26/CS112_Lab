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

    for (int i = 0; i < size; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] < 0 && arr[i + 1] > 0)
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
}