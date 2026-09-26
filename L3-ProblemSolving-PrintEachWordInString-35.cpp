#include <string>
#include <iostream>
using namespace std;

string ReadString()
{
	string String;
	cout << "Enter Your String : \n";
	getline(cin, String);
	return String;
}


void PrintEachWordInString(string str)
{
	string delim = " ";
	short pos = 0;
	string sword;

	while ((pos = str.find(delim)) != string::npos) 
	{
		sword = str.substr(0, pos);
		if (sword != "")
		{
			cout << sword << endl;
		}
		str.erase(0, pos + delim.length());
	}
	if (str != "")
	{
		cout << str << endl;
	}
}

int main()
{
	string String = ReadString();

	PrintEachWordInString(String);

	system("pause>0");
}