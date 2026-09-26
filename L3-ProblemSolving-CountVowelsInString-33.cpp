#include <string>
#include <iostream>
using namespace std;

string ReadString()
{
	string String;
	cout << "Enter Your String : \n";
	cin >> String;
	return String;
}

bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1
		== 'o') || (Ch1 == 'u'));
}

int CountVowels(string str)
{
	short counter = 0;
	for (int i = 0; i < str.length();i++)
	{
		if (IsVowel(str[i]))
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	string String = ReadString();
	
	cout << "Number of Vowels is : " << CountVowels(String) << endl;

	system("pause>0");
}