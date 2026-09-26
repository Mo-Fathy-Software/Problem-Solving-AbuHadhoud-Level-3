#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            cout << arr[i][j] << "     ";
        }
        cout << "\n";
    }
}


bool IsPalindromeMatrix(int Matrix[3][3], short rows, short cols)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols / 2;j++)
        {
            if (Matrix[i][j] != Matrix[i][cols - 1-j])
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
    PrintMatrix(Matrix, 3, 3);
    cout << "\n";
    cout << "___________________________\n";
    if (IsPalindromeMatrix(Matrix, 3, 3))
    {
        cout << "\nYes: Matrix is Palindrome\n";
    }
    else
        cout << "\nNo: Matrix is NOT Palindrome\n";
}