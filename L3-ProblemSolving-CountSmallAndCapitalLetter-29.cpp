#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
char InvertLetterCase(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}
string InvertAllStringLettersCase(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLetterCase(S1[i]);
	}
	return S1;
}
int StringLength(string S1)
{
	int LengthOfStr = S1.length();
	
	return LengthOfStr;
}
int CapitalLetterCount(string S1)
{
	short CapitalLetter = 0;
	for (int i = 0;i <= S1.length();i++)
	{
		if (isupper(S1[i]))
			CapitalLetter++;
	}
	return CapitalLetter;
}
int SmallLetterCount(string S1)
{
	short SmallLetter = 0;
	for (int i = 0;i <= S1.length();i++)
	{
		if (islower(S1[i]))
			SmallLetter++;
	}
	return SmallLetter;
}

int main()
{
	string S1 = ReadString();
	cout << "\n\nStringLength = " << StringLength(S1);
	cout << "\nCapital Letter Count = "<<CapitalLetterCount(S1);
	cout << "\nSmall Letter Count = "<< SmallLetterCount(S1);
	system("pause>0");
}