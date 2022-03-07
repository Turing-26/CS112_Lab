#include <iostream>

using namespace std;

class small_set
{
private:
    int tot = 32;
    int *nums = new int[tot];

public:
    void init()
    {
        for (int i = 0; i < tot; i++)
        {
            nums[i] = -1;
        }
    }
    void set(int item)
    {
        if (item < 0 && item > 31)
        {
            cout << "Invalid number....";
            return;
        }
        nums[item] = item;
    }
    void clear(int item)
    {
        if (item < 0 && item > 31)
        {
            cout << "Invalid number....";
            return;
        }
        for (int i = 0; i < tot; i++)
        {
            if (item == nums[i])
                nums[i] = -1;
        }
    }
    int test(int num)
    {
        for (int i = 0; i < tot; i++)
        {
            if (num == nums[i] && num != -1)
                return 1;
        }
        return 0;
    }
};

int main()
{
    small_set a_set;
    a_set.init();
    a_set.set(3);
    a_set.set(5);
    cout << a_set.test(3) << endl;
    cout << a_set.test(0) << endl;
}