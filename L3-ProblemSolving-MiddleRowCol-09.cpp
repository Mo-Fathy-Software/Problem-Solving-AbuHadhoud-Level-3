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

void MiddleRowOfMatrix(int arr[3][3], short rows, short cols)
{
    short MiddleRows = rows / 2;
    for (int i = 0; i < rows;i++)
    {
        printf(" %0*d    ", 2, arr[i][MiddleRows]);
    }
}
void MiddleColOfMatrix(int arr[3][3], short rows, short cols)
{
    short MiddleCols = cols / 2;
    for (int j =0;j < cols ;j++)
    {
        printf(" %0*d    ", 2, arr[MiddleCols][j]);
    }

}


int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3], arr2[3][3], arr3[3][3];
    FillRandomMatrix(arr, 3, 3);
    cout << "The Following is 3*3 Random Matrix 1: " << endl;
    PrintMatrix(arr, 3, 3);
    cout << "Middle Row Of Matrix one is : " << endl;
    MiddleRowOfMatrix(arr,3,3);
    cout << "\nMiddle Col Of Matrix one is : " << endl;
    MiddleColOfMatrix(arr, 3, 3);

}