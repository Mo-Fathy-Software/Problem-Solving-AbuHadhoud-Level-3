#include <iostream>
using namespace std;


void PrintFibonacciUsingLoop(short Number)
{
    if (Number <= 0) return;

    int Prev2 = 0, Prev1 = 1;

    for (short i = 1; i <= Number; ++i)
    {
        cout << Prev1 << " "; // طباعة العنصر الحالي أولاً
        int FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
    cout << endl;
}

int main()
{
    PrintFibonacciUsingLoop(14);
    return 0;
}