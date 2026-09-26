#include <string>
#include <iostream>
#include <vector>
using namespace std;

string ReadString()
{
	string String;
	cout << "Please enter your string?\n";
	getline(cin, String);
	return String;
}
string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringtoReplace, string Replaceto)
{
	short pos = S1.find(StringtoReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringtoReplace.length(), Replaceto);
		pos = S1.find(StringtoReplace);
	}
	return S1;
}

int main()
{
	string S1 = ReadString();
	string StringToReplace = "";
	string ReplaceTo = "";

	cout << "What's a string to replace? \n";
	cin >> StringToReplace;

	cout << "What's a string to replace to ? \n";
	cin >> ReplaceTo;
	cout << "\nOrigial String\n" << S1;
	cout << "\n\nString After Replace:";
	cout << "\n" << ReplaceWordInStringUsingBuiltInFunction(S1,
		StringToReplace, ReplaceTo);
	system("pause>0");
}