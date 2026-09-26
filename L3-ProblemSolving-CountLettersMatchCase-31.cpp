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

int CountLetter(string S1, char letter,bool MatchCase = true)
{
	short counter = 0;
	for (int i = 0;i < S1.length();i++)
	{
		if (MatchCase)
		{
			if (S1[i] == letter)
				counter++;
		}
		else
		{
			if (tolower(S1[i]) == tolower(letter))
			{
				counter++;
			}
		}
	}
	return counter;

}

int main()
{
	string S1 = ReadString();
	char Letter;
	cout << "Enter the Letter to Count : \n";
	cin >> Letter;
	cout << "\nLetter '"<< Letter <<"'  Count = " << CountLetter(S1, Letter);
	cout << "\nLetter '"<< InvertLetterCase(Letter) <<"' & 'm' = " << CountLetter(S1, Letter,false);

	system("pause>0");
}