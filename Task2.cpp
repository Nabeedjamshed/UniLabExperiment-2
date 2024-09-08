#include <iostream>
using namespace std;

class Matrix
{
private:
    int mat[3][3];
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter the value of " << i + 1 << " row and " << j + 1 << " column ";
                cin >> mat[i][j];
            }
        }
    }

    void display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void transpose() const
    {
        int res[3][3] = {};
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res[j][i] = mat[i][j];
            }
        }
        cout << "Transposed Matrix:" << endl;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    void multiplyConstant(int constant) const
    {
        int res[3][3] = {};
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res[i][j] = mat[i][j] * constant;
            }
        }
        cout << "Matrix after multiplication by " << constant << ":" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    void add(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Addition not possible!" << endl;
            return;
        }
        int res[3][3] = {};
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        cout << "Result of matrix addition:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    void subtract(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Subtraction not possible!" << endl;
            return;
        }
        int res[3][3] = {};
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                res[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        cout << "Result of matrix subtraction:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    void multiply(const Matrix &other) const
    {
        if (cols != other.rows)
        {
            cout << "Multiplication not possible!" << endl;
            return;
        }
        int res[3][3] = {};
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    res[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        cout << "Result of matrix multiplication:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
};

void rows_cols(int &r1, int &c1, int &r2, int &c2)
{
    cout << "Enter number of rows for matrix 1: ";
    cin >> r1;
    cout << "Enter number of columns for matrix 1: ";
    cin >> c1;
    cout << "Enter number of rows for matrix 2: ";
    cin >> r2;
    cout << "Enter number of columns for matrix 2: ";
    cin >> c2;
}

int main()
{
    int choice;
    do
    {
        cout << "\nWhich operation do you want to perform?" << endl;
        cout << "1. Transpose of a Matrix" << endl;
        cout << "2. Multiply a matrix with a constant" << endl;
        cout << "3. Addition of 2 matrices" << endl;
        cout << "4. Subtraction of 2 matrices" << endl;
        cout << "5. Multiplication of 2 matrices" << endl;
        cout << "Enter your choice (0 to exit): ";
        cin >> choice;

        if (choice == 0)
            cout<<"Exit...";
            break;

        switch (choice)
        {
        case 1:
        {
            int r1, c1;
            cout << "Enter number of rows: ";
            cin >> r1;
            cout << "Enter number of columns: ";
            cin >> c1;
            Matrix mat1(r1, c1);
            mat1.transpose();
            break;
        }
        case 2:
        {
            int r1, c1;
            cout << "Enter number of rows: ";
            cin >> r1;
            cout << "Enter number of columns: ";
            cin >> c1;
            Matrix mat1(r1, c1);
            int constant;
            cout << "Enter the constant: ";
            cin >> constant;
            mat1.multiplyConstant(constant);
            break;
        }
        case 3:
        {
            int r1, c1, r2, c2;
            rows_cols(r1, c1, r2, c2);
            Matrix mat1(r1, c1);
            Matrix mat2(r2, c2);
            mat1.add(mat2);
            break;
        }
        case 4:
        {
            int r1, c1, r2, c2;
            rows_cols(r1, c1, r2, c2);
            Matrix mat1(r1, c1);
            Matrix mat2(r2, c2);
            mat1.subtract(mat2);
            break;
        }
        case 5:
        {
            int r1, c1, r2, c2;
            rows_cols(r1, c1, r2, c2);
            Matrix mat1(r1, c1);
            Matrix mat2(r2, c2);
            mat1.multiply(mat2);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

