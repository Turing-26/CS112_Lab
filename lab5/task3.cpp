#include <iostream>

using namespace std;

class stringType
{
private:
    string first;
    string second;

public:
    stringType() : first(""), second(""){};
    stringType(string str1, string str2)
    {
        first = str1;
        second = str2;
    };
    void setValues(string str1, string str2)
    {
        first = str1;
        second = str2;
    }
    void printValues()
    {
        cout << "First string: " << first << endl;
        cout << "Second string: " << second << endl;
    }
    int maxLength()
    {
        // Finds maximum length of the longest string
        int i = 0, j = 0, len;
        while (first[i] != '\0' || second[j] != '\0')
        {
            if (first[i] != '\0')
                i++;
            if (second[j] != '\0')
                j++;
        }
        j < i ? len = i : len = j;
        return len;
    }
    int compare(string s1, string s2)
    {
        int diff, i = 0;

        while (s2[i] != '\0')
        {
            if (s1[i] != s2[i])
            {
                // Returns difference between ascii code of first differing characters
                diff = s1[i] - s2[i];
                return diff;
            }
            i++;
        }
        return 0;
    }
    void copy(string source, string destination)
    {
        // Copies string at source and returns copied string
        destination = source;
        cout << destination << endl;
    }
    string concatenate(string s1, string s2)
    {
        string resStr = s1 + s2;
        return resStr;
    }
    int searchWord(string word)
    {
        // Total characters and words in string
        int ch = 0, sp = 0;

        while (1)
        {
            if (first[ch] == ' ' || first[ch] == ',' || first[ch] == '.' || first[ch] == '\0')
                sp++;
            ch++;
            if (first[ch] == '\0')
                break;
        }

        int k = 0;
        for (int j = 0; j < sp + 1; j++)
        {
            string temp = "";
            while (1)
            {
                if (first[k] == ' ' || first[k] == ',' || first[k] == '.' || first[k] == '\0')
                {
                    k++;
                    break;
                }
                temp += first[k];
                k++;
            }
            if (word == temp)
                return 1;
        }
        return 0;
    }
    int searchChar(char ch)
    {
        int i = 0, j = 0;
        while (1)
        {
            if (first[i] == ch || second[j] == ch)
                return 1;

            if (first[i] != '\0')
                i++;
            if (second[j] != '\0')
                j++;
            if (first[i] == '\0' && second[j] == '\0')
                break;
        }
        return 0;
    }
};

int main()
{
    stringType strs;
    string st1, st2, word;
    int choice = 0;

    while (1)
    {
        cout << "----------------------------------------------\n";
        cout << "1. To set values\n";
        cout << "2. To print all strings\n";
        cout << "3. To find maximum lnegth\n";
        cout << "4. To compare 2 strings\n";
        cout << "5. To copy a string to another\n";
        cout << "6. To concatenate 2 strings\n";
        cout << "7. To search for a word in the strings\n";
        cout << "8. To search for a character in the strings\n";
        cout << "----------------------------------------------\n";
        cout << "Enter option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter first string: ";
            getline(cin >> ws, st1);
            cout << "Enter second string: ";
            getline(cin, st2);
            strs.setValues(st1, st2);
            break;
        case 2:
            strs.printValues();
            break;
        case 3:
            cout << "The maximum length is: " << strs.maxLength() << endl;
            break;
        case 4:
            cout << "Enter first string: ";
            getline(cin >> ws, st1);
            cout << "Enter second string: ";
            getline(cin, st2);
            cout << "Difference is: " << strs.compare(st1, st2) << endl;
            break;
        case 5:
            cout << "Enter string to copy: ";
            getline(cin >> ws, st1);
            strs.copy(st1, st2);
            break;
        case 6:
            cout << "Enter first string: ";
            getline(cin >> ws, st1);
            cout << "Enter second string: ";
            getline(cin, st2);
            cout << strs.concatenate(st1, st2) << endl;
            break;
        case 7:
            cout << "Enter word to search: ";
            cin >> word;
            cout << strs.searchWord(word) << endl;
            break;
        case 8:
            char ch;
            cout << "Enter character to search: ";
            cin >> ch;
            cout << strs.searchChar(ch) << endl;
            break;
        }
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8)
            break;
    }
}