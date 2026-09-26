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
string UpperString(string S1)
{
	for (int i = 0;i <= S1.length();i++)
	{
		S1[i]=toupper(S1[i]);
	}
	return S1;
}
string LowerString(string S1)
{
	for (int i = 0;i <= S1.length();i++)
	{
		S1[i]=tolower(S1[i]);
	}
	return S1;
}
int main()
{
	string S1 = ReadString();
	cout << "String After Conversion: \n";
	cout << "All string to Upper : \n" << UpperString(S1) << endl;

	cout << "\nAll string to Lower : \n" << LowerString(S1) << endl;

	system("pause>0");
}
 