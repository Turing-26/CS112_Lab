#include <iostream>

using namespace std;

class Parity
{
private:
    int items;
    int *arr = new int[items];

public:
    Parity() : items(0) {}
    Parity(int num) : items(num)
    {
        if (items < 0)
        {
            items = 0;
            return;
        }
        for (int i = 0; i < items; i++)
        {
            cout << "Enter value: ";
            cin >> arr[i];
        }
    }
    ~Parity()
    {
        delete[] arr;
    }

    void put(int num)
    {
        items++;
        int *temp = new int[items];

        for (int i = 0; i < items - 1; i++)
        {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        arr[items - 1] = num;
    }

    void print()
    {
        for (int i = 0; i < items; i++)
        {
            cout << "El " << i + 1 << ": " << arr[i] << endl;
        }
    }

    void delItem()
    {
        if (items == 0)
        {
            cout << "No items can be deleted..";
            return;
        }

        items--;
        int *temp = new int[items];

        for (int i = 0; i < items; i++)
        {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

    int test()
    {
        return items % 2;
    }
};

int main()
{
    Parity nums;
    int choice;

    while (1)
    {
        cout << "----------------------------------------------\n";
        cout << "1. To put a number\n";
        cout << "2. To print all numbers\n";
        cout << "3. To delete last number\n";
        cout << "4. To test if total items are an odd or even number\n";
        cout << "----------------------------------------------\n";
        cout << "Enter option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int input;
            cout << "What do you want to add: ";
            cin >> input;
            nums.put(input);
            break;
        case 2:
            nums.print();
            break;
        case 3:
            nums.delItem();
            break;
        case 4:
            cout << nums.test();
            break;
        }
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
            break;
    }
}