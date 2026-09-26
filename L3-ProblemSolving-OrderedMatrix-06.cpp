#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillOrderedMatrix(int arr[3][3], short rows, short cols)
{
    int Counter = 0;
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            Counter++;
            arr[i][j] = Counter;
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    int Number = 0;
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << "\n";
    }
}



int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    int arr1[3];
    FillOrderedMatrix(arr, 3, 3);
    cout << "The Following is 3*3 Random Matrix : " << endl;
    PrintMatrix(arr, 3, 3);
}