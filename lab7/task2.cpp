#include <iostream>

using namespace std;

class Matrix
{
    int r, c;
    int **arr;

public:
    Matrix(int row = 0, int col = 0)
    {
        if (row == 0 || col == 0)
        {
            cout << "Enter the number of rows: ";
            cin >> r;
            cout << "Enter the number of columns: ";
            cin >> c;
        }
        else
        {
            r = row;
            c = col;
        }

        arr = new int *[r];

        for (int i = 0; i < r; i++)
        {
            arr[i] = new int[c];
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                arr[i][j] = i + j;
            }
        }
    }
    ~Matrix()
    {
        // for (int i = 0; i < r; i++)
        // {
        //     delete[] arr[i];
        // }
        // delete[] arr;
    }

    Matrix operator+(Matrix &m2)
    {
        if (this->r != m2.r || this->c != m2.c)
            return *this;

        Matrix res(this->r, this->c);
        for (int i = 0; i < this->r; i++)
        {
            for (int j = 0; j < this->c; j++)
            {
                res.arr[i][j] = this->arr[i][j] + m2.arr[i][j];
            }
        }
        return res;
    }

    Matrix operator-(Matrix &m2)
    {
        if (this->r != m2.r || this->c != m2.c)
            return *this;

        Matrix res(this->r, this->c);
        for (int i = 0; i < this->r; i++)
        {
            for (int j = 0; j < this->c; j++)
            {
                res.arr[i][j] = arr[i][j] - m2.arr[i][j];
            }
        }
        return res;
    }

    Matrix operator*(Matrix &m2)
    {
        if (this->c != m2.r)
            return *this;

        Matrix res(this->r, m2.c);
        for (int i = 0; i < this->r; i++)
        {
            for (int j = 0; j < m2.c; j++)
            {
                for (int k = 0; k < this->c; k++)
                {
                    res.arr[i][j] += arr[i][k] * m2.arr[k][j];
                }
            }
        }
        return res;
    }

    friend ostream &operator<<(ostream &COUT, Matrix &m)
    {
        for (int i = 0; i < m.r; i++)
        {
            for (int j = 0; j < m.c; j++)
            {
                COUT << m.arr[i][j] << "  ";
            }
            COUT << endl;
        }
        return COUT;
    }
};

int main()
{
    Matrix m1, m2, res = m1 + m2;
    cout << res << endl;
    res = m1 - m2;
    cout << res << endl;
    res = m1 * m2;
    cout << res << endl;
}