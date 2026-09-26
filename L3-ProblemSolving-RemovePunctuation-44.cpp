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

string RemovePunctuation(string S1)
{
	string S2 = "";
	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}
	return S2;
}

int main()
{
	string S1 = ReadString();
	cout << "\nOriginal String: " << S1 << endl;
	cout << "Puctuation Removed : " << RemovePunctuation(S1);
	system("pause>0");
}