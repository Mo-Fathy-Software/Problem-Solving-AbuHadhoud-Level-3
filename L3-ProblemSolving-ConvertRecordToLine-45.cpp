#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct ClientData
{
	string AccountNumber = "";
	string Name ;
	string Phone = "";
	string PinCode = "";
	double AccountBalance;
};
ClientData ReadClientData()
{
	ClientData Client;
	cout << "Enter Account Number? ";
	getline(cin, Client.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string PrintClientDataInLine(ClientData Client1)
{
	string Sp = "#//#";
	string S1 = "";

	S1 += Client1.AccountNumber;
	S1 += Sp;
	S1 += Client1.PinCode;
	S1 += Sp;
	S1 += Client1.Name;
	S1 += Sp;
	S1 += Client1.Phone;
	S1 += Sp;
	S1 += to_string(Client1.AccountBalance);
	return S1;
}

int main()
{

	ClientData Client;
	Client = ReadClientData();
	cout << "\n\nClient Record for Saving is: \n";
	cout << PrintClientDataInLine(Client);
	return 0;
}
