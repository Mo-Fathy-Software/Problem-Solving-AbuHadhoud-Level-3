#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillRandomMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            arr[i][j] = RandomNumber(0, 1);
        }
    }
}

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



bool IsScalerMatrix(int Matrix1[3][3], short rows, short cols)
{
    int FirstDiagElement = Matrix1[0][0];
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            //Check for diagonals elemets
            if (i == j && Matrix1[i][j] != FirstDiagElement)
                return false;
            //check for rest elements
            else if (i != j && Matrix1[i][j] != 0)
                return false;
        }
    }
    return true;
}
int main()
{
    srand((unsigned)time(NULL));
    int Matrix1[3][3]{ {9,0,0},{0,2,0},{0,0,9} };
    PrintMatrix(Matrix1, 3, 3);
    if (IsScalerMatrix(Matrix1, 3, 3))
        cout << "\nYes: Matrix is Scalar.\n";
    else
        cout << "NO : Matrix is NOT Scaler.\n ";

}