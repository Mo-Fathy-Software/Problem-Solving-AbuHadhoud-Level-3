#include <iostream>
#include <string>
using namespace std;


string ReadString()
{
	string S1;
	cout << "Please enter your string ? \n";
	getline(cin, S1);
	return S1;
}
void PrintTheFirstLetterOfEachWord(string S1)
{
	bool IsFirstLetter = true;
	for (short i = 0; i <= S1.length();i++)
	{
		if (i != ' ' && IsFirstLetter)
		{
			cout << S1[i] ;
		}
		IsFirstLetter = (S1[i] == ' ' ? true : false);
	}

}
int main()
{
	PrintTheFirstLetterOfEachWord(ReadString());
}