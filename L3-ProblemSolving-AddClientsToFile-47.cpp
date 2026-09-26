#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct ClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};
ClientData ReadClientData()
{
	ClientData Client;
	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);
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

void AddDataLineToFile(string FileName,string DataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << DataLine;
		MyFile << "\n";
		MyFile.close();
	}
}

string ConvertClientDataInLine(ClientData Client1)
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

void AddClientData()
{
	cout << "Adding New Client: \n";
	ClientData Client = ReadClientData();
	AddDataLineToFile(ClientsFileName, ConvertClientDataInLine(Client));
}
void AddClients()
{
	char AddAgain = 'Y';
	do
	{
		system("cls");
		AddClientData();
		cout << "Client Added Succesfully Do you want to Add more Clients? [Y] or [N] \n";
		cin >> AddAgain;
	} while (toupper(AddAgain) == 'Y');
}
int main()
{
	AddClients();
}