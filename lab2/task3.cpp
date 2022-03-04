#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

#define READ(type, var) type var; cin >> var;

bool checkNum(int num, int base) {
    string str;
    base == 16 ? str = num : str = to_string(num);

    if (base == 2) {
        for (int i = 0; i < str.length(); i++) {
            if (int(str[i]) != 48 && int(str[i]) != 49)
                return false;
        }
    } else if (base == 8) {
        for (int i = 0; i < str.length(); i++) {
            if (int(str[i]) < 48 || int(str[i]) > 55)
                return false;
        }
    } else if (base == 16) {
        for (int i = 0; i < str.length(); i++) {
            if (int(str[i]) < 48 || (int(str[i]) > 55 && int(str[i]) < 65) || int(str[i]) > 70)
                return false;
        }
    }
    return true;
}

void convertLogic(int num, int curBase, int newBase, int *newNum, string numStr = "") {
    int rem = 0, base1 = 1;

    if (curBase != 16 && newBase == 10) {
        while(num > 0) {
            rem = num % newBase;
            *newNum = *newNum + rem*base1;
            num = num / newBase;
            base1 = base1 * curBase;
        }
    } else if (newBase == 16) {
        string rem[numStr.length()];

        for (int i = 0; i < numStr.length(); i++) {
            int n = num % 16;
            num = num / 16;
            char nCh;

            n > 9 ? nCh = char(n+55) : nCh = char(n+48);
            rem[i] = nCh;
        }
        for (int i = numStr.length()-1; i >= 0; i--)
            cout << rem[i];
    } else {
        for (int i = 0; i < numStr.length()/2; i++) {
            swap(numStr[i], numStr[numStr.length()-i-1]);
        }

        for (int i = 0; i < numStr.length(); i++) {
            int n;
            if (int(numStr[i]) > 47 && int(numStr[i]) < 58)
                n = numStr[i] - '0';
            else
                n = numStr[i] - 55;
            
            *newNum = *newNum + (n*pow(curBase,i));
        }
    }
}

int convert(int num, int base, int con, string numStr = "") {
    int newNum = 0;

    if (base == 2) {
        convertLogic(num, base, con, &newNum);
        return newNum;
    } else if (base == 8) {
        convertLogic(num, base, con, &newNum);
        return newNum;
    } else if (base == 10 && con == 8) {
        convertLogic(num, base, con, &newNum);
        return newNum;
    } else if (base == 16 && con == 10) {
        convertLogic(0, base, con, &newNum, numStr);
        return newNum;
    } else if (base == 10 && con == 16) {
        // cout << "hello";
        convertLogic(num, base, con, &newNum, numStr);
    }
    return 0;
}

int main() {
    int base, result;

    cout << "Enter the base: ";
    cin >> base;

    while(1) {
        if (base == 2 || base == 8 || base == 10 || base == 16)
            break;
        else {
            cout << "Invalid input, please enter the base again (2, 8, 10, 16): ";
            cin >> base;
        }
    }

    if (base == 2) {
        cout << "Enter number 1 with base " << base << ": ";
        READ(int, num1);
        cout << "Enter number 2 with base " << base << ": ";
        READ(int, num2);
        num2 = convert(num2, base, 10);
        num2 = convert(num2, base, 10);

        while(!checkNum(num1, base) && !checkNum(num2, base)) {
            cout << "Invalid inputs, enter again in correct base: ";
            cin >> num1 >> num2;
        }

        result = num1 + num2;
        cout << "The result is: " << bitset<8>(result);
    } else if (base == 8) {
        cout << "Enter number 1 with base " << base << ": ";
        READ(int, num1);
        cout << "Enter number 2 with base " << base << ": ";
        READ(int, num2);

        while(!checkNum(num1, base) && !checkNum(num2, base)) {
            cout << "Invalid inputs, enter again in correct base: ";
            cin >> num1 >> num2;
        }

        num1 = convert(num1, base, 10);
        num2 = convert(num2, base, 10);

        result = num1 + num2;
        cout << "The result is: " << convert(result, 10, base);
    } else if (base == 16) {
        cout << "Enter number 1 with base " << base << ": ";
        READ(string, num1);
        cout << "Enter number 2 with base " << base << ": ";
        READ(string, num2);

        int newNum1 = convert(0, base, 10, num1);
        int newNum2 = convert(0, base, 10, num2);

        result = newNum1 + newNum2;
        string resStr = to_string(result);
        cout << "The result is: " << newNum1 << " " << newNum2 << endl;
        cout << "The result is: ";
        convert(result, 10, 16, resStr);
    }
}