#include <iostream>

using namespace std;

class twoDArray
{
private:
    int size = 3;
    int **mat;

public:
    void initialize(int par = 0)
    {
        mat = new int *[size];
        for (int i = 0; i < size; i++)
        {
            mat[i] = new int[size];
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (par == 0)
                    cin >> mat[i][j];
                else
                    mat[i][j] = 0;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void transpose()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << mat[j][i] << "\t";
            }
            cout << endl;
        }
    }

    bool symmetric()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (mat[i][j] != mat[j][i])
                    return false;
            }
        }
        return true;
    }

    twoDArray multiply(twoDArray mat1, twoDArray mat2)
    {
        twoDArray res;
        res.initialize(1);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    res.mat[i][j] += mat1.mat[i][k] * mat2.mat[k][j];
                }
            }
        }

        return res;
    }
};

int main()
{
    int choice;
    twoDArray A, B;

    while (1)
    {
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "ENTER THE VALUE TO SELECT OPTION: \n";
        cout << "\t1. Transpose of a matrix\n";
        cout << "\t2. Is the matrix Symmetric\n";
        cout << "\t3. Multiply two matrices\n";
        cout << "\t0. Exit\n";
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "ENTER OPTION: ";
        cin >> choice;

        if (choice == 0)
            break;

        switch (choice)
        {
        case 1:
            A.initialize();
            A.transpose();
            break;
        case 2:
            A.initialize();
            cout << A.symmetric() << endl;
            break;
        case 3:
        {
            A.initialize();
            B.initialize();

            twoDArray res = A.multiply(A, B);
            res.print();
            break;
        }
        default:
            cout << "Invalid option selected, try again.....";
        }
    }
}