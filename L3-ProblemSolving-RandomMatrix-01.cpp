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
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}
void PrintRandomMatrix(int arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            cout <<setw(3) << arr[i][j] << "    ";
        }
        cout << "\n";
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[3][3];
    FillRandomMatrix(arr,3,3);
    cout << "The Following is 3*3 Random Matrix : " << endl;
    PrintRandomMatrix(arr,3,3);
}