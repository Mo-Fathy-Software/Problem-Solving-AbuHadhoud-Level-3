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

void MultiplyTwoFN(int arr[3][3], int arr2[3][3], int arr3[3][3], short rows, short cols)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            arr3[i][j] = arr[i][j] * arr2[i][j];
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


int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3],arr2[3][3], arr3[3][3];
    FillRandomMatrix(arr, 3, 3);
    cout << "The Following is 3*3 Random Matrix 1 : " << endl;
    PrintMatrix(arr, 3, 3);
    FillRandomMatrix(arr2, 3, 3);
    cout << "The Following is 3*3 Random Matrix 2 : " << endl;
    PrintMatrix(arr2, 3, 3);
    cout << "___________________________\n";
    cout << "Print Results: \n";
    MultiplyTwoFN(arr,arr2,arr3,3,3);
    PrintMatrix(arr3, 3, 3);
}