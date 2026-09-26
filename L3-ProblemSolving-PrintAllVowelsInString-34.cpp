#include <string>
#include <iostream>
using namespace std;

string ReadString()
{
	string String;
	cout << "Enter Your String : \n";
	getline(cin,String);
	return String;
}

bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1
		== 'o') || (Ch1 == 'u'));
}

void PrintAllVowels(string str)
{
	cout << "\nNumber of Vowels is : " ;
	for (int i = 0; i < str.length();i++)
	{
		if (IsVowel(str[i]))
		{
			cout <<  str[i] << "   ";
		}
	}
}

int main()
{
	string String = ReadString();

	PrintAllVowels(String);

	system("pause>0");
}