#include <string>
#include <iostream>
using namespace std;


bool IsVowelOrNot(char Vowel)
{
	char vowels[5] = {'a','e','i','o','u'};
	for (int i = 0;i < 5;i++)
	{
		if (vowels[i] == tolower(Vowel))
		{
			return true;
		}
	}
	return false;
}



int main()
{
	char Vowel;
	cout << "Enter the Character to check : \n";
	cin >> Vowel;
	if (IsVowelOrNot(Vowel))
		cout << "Yes Letter '" << Vowel << "' is vowel";
	else
		cout << "No Letter '" << Vowel << "' is Not vowel";

	system("pause>0");
}