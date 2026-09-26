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

int LetterCount(string S1,char letter)
{
	short counter = 0;
	for (int i = 0;i <= S1.length();i++)
	{
		if (S1[i] == letter)
			counter++;
	}
	return counter;
	
}

int main()
{
	string S1 = ReadString();
	char Letter;
	cout << "Enter the Letter to Count : \n";
	cin >> Letter;
	cout << "\nLetter Count = " << LetterCount(S1,Letter);
	system("pause>0");
}