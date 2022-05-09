#include <iostream>

using namespace std;

class BankAccount
{
protected:
    int accNumber;
    double balance;

public:
    BankAccount()
    {
        cout << "Enter account number: ";
        cin >> accNumber;
        balance = 0;
    }
    ~BankAccount() {}

    int retAccn()
    {
        return accNumber;
    }

    double retBal()
    {
        return balance;
    }

    void deposit()
    {
        double dep;
        cout << "Enter money to be deposited: ";
        cin >> dep;

        balance += dep;
    }

    double withdraw()
    {
        double wd;
        cout << "Enter money you want to withdraw: ";
        cin >> wd;

        if (balance >= wd)
        {
            balance -= wd;
            return wd;
        }
        else
            cout << "Sorry, insufficient balance";
        return 0;
    }

    void print()
    {
        cout << "Account number : " << accNumber << endl;
        cout << "Account balance : " << balance << endl;
    }
};

class CheckingAccount : protected BankAccount
{
    double minBal;
    int interest;
    int surChargeAmount;
    int surCharge;

public:
    CheckingAccount()
    {
        BankAccount();
        cout << "Enter minimum balance: ";
        cin >> minBal;
        cout << "Enter interest rate: ";
        cin >> interest;
        cout << "Enter service charges: ";
        cin >> surChargeAmount;
    }
    ~CheckingAccount() {}

    int retInt()
    {
        return interest;
    }

    void setInt()
    {
        cout << "Enter new interest rate: ";
        cin >> interest;
    }

    void setMin()
    {
        cout << "Enter new minimum balance: ";
        cin >> minBal;
    }

    double retMinBal()
    {
        return minBal;
    }

    void setSerCh()
    {
        cout << "Enter new service charges: ";
        cin >> surChargeAmount;
    }

    int retCharges()
    {
        return surCharge;
    }

    double postInt()
    {
        balance += balance * (interest / 100);
        return balance;
    }

    double withdraw()
    {
        if (balance < minBal)
        {
            surCharge += surChargeAmount;
            return 0;
        }
        else
        {
            return BankAccount::withdraw();
        }
    }

    void print()
    {
        BankAccount::print();
    }
};

class SavingsAccount : protected BankAccount
{
    int interest;

public:
    SavingsAccount()
    {
        BankAccount();
        cout << "Enter interest rate: ";
        cin >> interest;
    }
    ~SavingsAccount() {}

    void setInt()
    {
        cout << "Set new interest rate: ";
        cin >> interest;
    }

    int retInt()
    {
        return interest;
    }

    double postInt()
    {
        balance += balance * (interest / 100);
        return balance;
    }

    double withdraw()
    {
        cout << "This is a savings account\n";
        BankAccount::withdraw();
    }

    void print()
    {
        BankAccount::print();
    }
};

int main()
{
    int choice;

    cout << "What account do you want to make(0 for checking, 1 for savings): ";
    cin >> choice;

    while (choice != 0 || choice != 1)
    {
        cout << "Enter again: ";
        cin >> choice;
    }

    if (choice == 0)
    {
        CheckingAccount ca;
        while (1)
        {
            int ch;
            cout << "--------------------------------------------\n";
            cout << "1. set interest rate\n";
            cout << "2. retrieve interest rate\n";
            cout << "3. set service charges\n";
            cout << "4. retrieve service charges\n";
            cout << "5. set minimum balance\n";
            cout << "6. retrieve minimum balance\n";
            cout << "7. post interest\n";
            cout << "8. withdraw\n";
            cout << "9. print account information\n";
            cout << "--------------------------------------------\n";
            cin >> ch;

            while (ch < 0 || ch > 9)
            {
                cout << "Enter a valid option: ";
                cin >> ch;
            }

            if (ch == 1)
            {
                ca.setInt();
            }
            else if (ch == 2)
            {
                cout << ca.retInt() << endl;
            }
            else if (ch == 3)
            {
                ca.setSerCh();
            }
            else if (ch == 4)
            {
                cout << ca.retCharges() << endl;
            }
            else if (ch == 5)
            {
                ca.setMin();
            }
            else if (ch == 6)
            {
                cout << ca.retMinBal() << endl;
            }
            else if (ch == 7)
            {
                cout << ca.postInt() << endl;
            }
            else if (ch == 8)
            {
                cout << ca.withdraw() << endl;
            }
            else if (ch == 9)
            {
                ca.print();
            }
        }
    }
}