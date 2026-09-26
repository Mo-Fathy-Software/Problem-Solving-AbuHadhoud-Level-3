#include <iostream>
#include <string>
using namespace std;


char ReadString()
{
	char Char1;
	cout << "Please enter your string ? \n";
	cin >> Char1;
	return Char1;
}
char InvertCharCase(char Char1)
{
	return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

int main()
{
	char Char1 = ReadString();
	cout << "Character After Conversion: \n";
	cout << InvertCharCase(Char1);
	system("pause>0");
}
