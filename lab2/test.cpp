#include <iostream>
#include <bitset>

using namespace std;

bool checkNum(int num, int base) {
    if (base == 2) {
        string str = to_string(num);
        cout << str << endl;
        for (int i = 0; i < str.length(); i++) {
            if (int(str[i]) != 48 && int(str[i]) != 49) {
                cout << str[i] << endl;
                return false;
            }
        }
        return true;
    }
    return true;
}

int main() {
    int num, rem = 0, base = 1;
    int newNum;
    bool t;
    enum hexa {A = 10, B, C, D, E};
    hexa replace;

    string str = "ABC";
    
    // string strArr[3];
    // bitset<16> var(string(str));

    // for (int i = 0; i < str.length(); i++) {
    //     strArr[i] = str[i];
    //     if (strArr[i] == "A")
    //         strArr[i] = to_string(A);
    // }

    // cout << str << endl << A << endl;

    // for (int i = 0; i < str.length(); i++) {
    //     cout << strArr[i];
    // }

    // cin >> num;

    // t = checkNum(num, 2);

    // while(num > 0) {
    //     rem = num % 10;
    //     newNum = newNum + rem*base;
    //     num = num / 10;
    //     base = base * 2;
    // }

    // cout << newNum << endl << t;
    // for (int i = 0; i < 8; i++) {
    //     cout << int(num[i]);
    // }
}