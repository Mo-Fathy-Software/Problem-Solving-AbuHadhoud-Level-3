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

vector <string> SpliteFunction(string S1, string delim)
{
	short pos = 0;
	string sWord;
	vector <string> vString;
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

string JoinFunction(vector <string>& vString, string sep)
{
	if (vString.empty()) return "";
	string S1 = "";
	for (string& s : vString)
	{

		S1 = S1 + s + sep;

	}
	return S1.substr(0, S1.length() - sep.length());
}

string LowerAllString(string S1)
{
	for (short i = 0;i <= S1.length();i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

string ReplaceWordInStringUsingSplit(string S1, string StringtoReplace, string Replaceto, bool MatchCase = true)
{
	vector <string> vString;
	vString = SpliteFunction(S1, " ");
	
	for (string& element : vString)
	{
		if (MatchCase)
		{
			if (element == StringtoReplace)
				element = Replaceto;
		}
		else
		{
			if (LowerAllString(element) ==
				LowerAllString(StringtoReplace))
			{
				element = Replaceto;
			}
		}
	}
	S1 = JoinFunction(vString, " ");
	return S1;
}


int main()
{
	string S1 = ReadString();
	string StringToReplace;
	string ReplaceTo;
	cout << "Please enter String to Replace?\n";
	cin >> StringToReplace;
	cout << "Please enter String to Replace To?\n";
	cin >> ReplaceTo;
	cout << "\nOriginal String:\n" << S1;
	cout << "\n\nReplace with match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1,
		StringToReplace, ReplaceTo);
	cout << "\n\nReplace with dont match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1,
		StringToReplace, ReplaceTo, false);
	system("pause>0");
}