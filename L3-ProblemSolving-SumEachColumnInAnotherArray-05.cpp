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
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintRandomMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << "\n";
    }
}

int ColumnSum(int arr[3][3], short rows, short cols)
{
    int Sum = 0;
    for (int i = 0; i < rows;i++)
    {

        Sum += arr[i][cols];
    }
    return Sum;
}

void ColumnSumInAnotherArray(int arr[3][3],int arr1[3], short rows, short cols)
{
    for (int j = 0;j < rows;j++)
    {
        arr1[j] = ColumnSum(arr, rows, j);
    }
}

void PrintColumnSum(int arr[3][3],int arr1[3], short rows, short cols)
{
    for (int j = 0;j < rows;j++)
    {
        cout << "Column " << j + 1 << " Sum = " << arr1[j] << endl;
    }
}



int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arr1[3];
    FillRandomMatrix(arr, 3, 3);
    cout << "The Following is 3*3 Random Matrix : " << endl;
    PrintRandomMatrix(arr, 3, 3);
    cout << "\nThe Following are the sum of each Column in the matrix: \n";
    ColumnSumInAnotherArray(arr, arr1, 3, 3);
    PrintColumnSum(arr,arr1, 3, 3);
}