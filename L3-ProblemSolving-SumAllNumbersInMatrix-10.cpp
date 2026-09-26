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

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf(" %0*d    ", 2, arr[i][j]);
        }
        cout << "\n";
    }
}

int PrintSumOfAllNumbers(int arr[3][3], short rows, short cols)
{
    int Sum = 0;
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            Sum += arr[i][j];
        }
    }
    return Sum;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3], arr2[3][3], arr3[3][3];
    FillRandomMatrix(arr, 3, 3);
    cout << "The Following is 3*3 Random Matrix 1: " << endl;
    PrintMatrix(arr, 3, 3);
    cout << "_______________________\n";
    cout << "Sum Of All Numbers In Matrix one is : " << PrintSumOfAllNumbers(arr,3,3);
    

}