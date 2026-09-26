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

vector <string>  SplitString(string S1,string delim)
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
string ReverseWordsInString(string S1)
{
	vector<string> vString;
	string S2 = "";
	vString = SplitString(S1, " ");
	// declare iterator
	vector<string>::iterator iter = vString.end();
	while (iter != vString.begin())
	{
		--iter;
		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() - 1); //remove last space.
	return S2;
}
int main()
{
	string S1 = ReadString();
	cout << "\n\nString after reversing words:";
	cout << "\n" << ReverseWordsInString(S1);
	system("pause>0");
}