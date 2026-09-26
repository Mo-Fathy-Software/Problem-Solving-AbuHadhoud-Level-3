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
int CountNumberInMatrix(int arr[3][3], short rows, short cols,short Number)
{
    short counter = 0;
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            if (Number == arr[i][j])
                counter++;
        }
    }
    return counter;
}



int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3]{ {9,6,0},{5,2,0},{5,3,9} };
    short Number;
    PrintMatrix(Matrix, 3, 3);
    cout << "___________________________\n";
    cout << "Please enter the number you need to count\n";
    cin >> Number;
    cout << "\nNumber " << Number << " is count : " << CountNumberInMatrix(Matrix, 3, 3, Number) << endl;

}