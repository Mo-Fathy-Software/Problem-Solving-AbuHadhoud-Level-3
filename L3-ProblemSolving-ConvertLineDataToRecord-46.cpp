#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct ClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};
void PrintClientData(ClientData Client)
{
	cout << "\nAccount Number: "<<Client.AccountNumber;
	cout << "\nPinCode       : "<<Client.PinCode;
	cout << "\nName          : "<<Client.Name;
	cout << "\nPhone         : "<<Client.Phone;
	cout << "\nAccountBalance: "<<Client.AccountBalance;
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


ClientData ConvertLineDataToRecord(string S1)
{
	ClientData Client;
	vector <string> vClientData;
	vClientData = SpliteFunction(S1, "#//#");
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;

}

int main()
{
	string S1 = "A150#//#1234#//#Mohamed Abu-Fathy#//#0799999#//#5270.000000\n";
	cout << "The Following is the extracted client record: \n";

	ClientData Client = ConvertLineDataToRecord(S1);
	PrintClientData(Client);
}
