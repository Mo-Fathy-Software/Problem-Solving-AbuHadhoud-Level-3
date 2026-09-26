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

bool NumberIsThereInMatrix(int arr[3][3],short Number, short rows, short cols)
{
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            if (Number == arr[i][j])
                return true;
        }
    }
    return false;
}



int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3]{ {9,0,0},{5,2,0},{0,0,9} };
    PrintMatrix(Matrix, 3, 3);
    short Number;

    cout << "___________________________\n";

    cout << "Please enter a Number to search?\n";
    cin >> Number;
    if (NumberIsThereInMatrix(Matrix,Number, 3, 3))
        cout << "Yes : It is there.\n";
    else
        cout << "No : It is Not there.\n";
}