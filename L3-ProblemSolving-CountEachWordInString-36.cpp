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


int CountEachWordInString(string str)
{
	string delim = " ";
	short pos = 0;
	string sword;
	short counter = 0;

	while ((pos = str.find(delim)) != string::npos)
	{
		sword = str.substr(0, pos);
		if (sword != "")
		{
			counter++;
		}
		str.erase(0, pos + delim.length());
	}
	return counter;

}

int main()
{
	string String = ReadString();

	cout << "Number of Words is : " << CountEachWordInString(String);

	system("pause>0");
}