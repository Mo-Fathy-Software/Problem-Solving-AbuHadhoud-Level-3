#include <string>
#include <iostream>
#include <vector>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}

string TrimLeft(string S1)
{
	for (int i = 0;i < S1.length();i++)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() -i);
		}
	}
	return "";
}
string TrimRight(string S1)
{
	for (int i = S1.length();i >0;i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i+1);	
		}
	}
	return "";
}

int main()
{
	string S1 = ReadString();
	cout << "String     :" << S1 << endl;
	cout << "Trim Left  :" << TrimLeft(S1) << endl;
	cout << "Trim Right :" << TrimRight(S1) << endl;
	cout << "TrimAll    :" << TrimLeft(TrimRight(S1));
	system("pause>0");
	
}