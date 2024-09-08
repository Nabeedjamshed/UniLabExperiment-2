#include <iostream>
using namespace std;

class MatrixSearch
{
private:
    int rows;
    int cols;
    int matrix[3][4];

public:
    MatrixSearch(int arr[3][4], int r, int c)
    {
        rows = r;
        cols = c;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                matrix[i][j] = arr[i][j];
            }
        }
    }
    bool binarySearch(int target)
    {
        int left = 0;
        int right = rows * cols - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int row = mid / cols;
            int col = mid % cols;

            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    int arr[3][4] = {{1, 3, 5, 7},
                     {10, 11, 16, 20},
                     {23, 30, 34, 60}};
    int n = 3;
    int m = 4;

    MatrixSearch sr(arr, n, m);

    int target;
    cout << "Enter the target number: ";
    cin >> target;

    bool found = sr.binarySearch(target);

    if (found)
    {
        cout << "True" << endl
             << "Target found in the matrix!" << endl;
    }
    else
    {
        cout << "False" << endl
             << "Target not found in the matrix." << endl;
    }

    return 0;
}