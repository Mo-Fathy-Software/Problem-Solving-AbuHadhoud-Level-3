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
int CountNumberInMatrix(int arr[3][3], short Number, short rows, short cols)
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

bool IsSparse(int arr[3][3], short rows, short cols)
{
    short MatrixSize = rows * cols;
    return CountNumberInMatrix(arr, 0, 3, 3) >= (MatrixSize/2);
}



int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3]{ {9,0,0},{5,2,0},{0,0,9} };
    PrintMatrix(Matrix, 3, 3);

    cout << "___________________________\n";
    if (IsSparse(Matrix, 3, 3))
        cout << "Yes : It is sparse.\n";
    else
        cout << "No : It is Not Sparse.\n";
}