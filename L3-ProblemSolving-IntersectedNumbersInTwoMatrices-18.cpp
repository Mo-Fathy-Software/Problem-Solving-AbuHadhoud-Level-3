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
bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows,
    short Cols)
{
    short NumberCount = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true;
            };
        }
    }
    return false;
}

void IntersectedNumber(int Matrix1[3][3],int Matrix2[3][3], short rows, short cols)
{
    short Number = 0;
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            Number = Matrix1[i][j];
            if (IsNumberInMatrix(Matrix2, Number, 3, 3))
            {
                cout << setw(3) << Number << "     ";
            }

        }
    }
}



int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

    PrintMatrix(Matrix1, 3, 3);
    cout << "\n";
    PrintMatrix(Matrix2, 3, 3);
    cout << "___________________________\n";
    cout << "\nIntersected Numbers are: \n\n";
    IntersectedNumber(Matrix1, Matrix2, 3, 3);

}