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
int main()
{
	vector <string> vString
	{ "Mohamed"
		,"Fathy",
		"Ramadan",
		"Abdo" };
	cout << "Vector After Join\n";
	cout << JoinFunction(vString, "@*");

}