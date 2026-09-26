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



bool IsIdentityMatrix(int Matrix1[3][3], short rows, short cols)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            //Check for diagonals elemets
            if (i == j && Matrix1[i][j] != 1)
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
    int Matrix1[3][3]{ {1,0,0},{0,1,0},{0,0,1} };
    PrintMatrix(Matrix1, 3, 3);
    if (IsIdentityMatrix(Matrix1,3, 3))
        cout << "\nYes: Matrix is Identity.\n";
    else
        cout << "NO : Matrix is NOT Identity.\n ";

}