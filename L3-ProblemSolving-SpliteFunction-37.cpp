#include <string>
#include <iostream>
#include <vector>
using namespace std;

string ReadString()
{
	string String;
	cout << "Enter Your String : \n";
	getline(cin, String);
	return String;
}


vector <string> SplitFunction(string str,string delim)
{
	short pos = 0;
	string sword;
	vector <string> vString;
	while ((pos = str.find(delim)) != string::npos)
	{
		sword = str.substr(0, pos);
		if (sword != "")
		{
			vString.push_back(sword);
		}
		str.erase(0, pos + delim.length());
	}
	if (str != "")
		vString.push_back(str);
	return vString;
}

int main()
{
	string String = ReadString();
	vector <string> vString = SplitFunction(String, " ");

	cout << "\nTokens = " << vString.size() << endl;
	for (string& s : vString)
	{
		cout << s << endl;
	}
	system("pause>0");
}