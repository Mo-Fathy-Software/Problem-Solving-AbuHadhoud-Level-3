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


int MaxNumber(int Matrix[3][3], short rows, short cols)
{
    int Number = Matrix[0][0];
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            if (Number < Matrix[i][j])
            {
                Number = Matrix[i][j];
            }
        }
    }
    return Number;
}
int MinNumber(int Matrix[3][3], short rows, short cols)
{
    short Number = Matrix[0][0];
    for (int i = 0; i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            if (Number > Matrix[i][j])
            {
                Number = Matrix[i][j];
            }
         
        }
    }
    return Number;
}


int main()
{
    srand((unsigned)time(NULL));
    int Matrix[3][3] = { {77,5,12},{22,200,1},{1,0,9} };
    PrintMatrix(Matrix, 3, 3);
    cout << "\n";
    cout << "___________________________\n";
    cout << "Max Number In Matrix : "<< MaxNumber(Matrix,3,3) << endl;
    cout << "Min Number In Matrix : "<< MinNumber(Matrix,3,3) << endl;

}