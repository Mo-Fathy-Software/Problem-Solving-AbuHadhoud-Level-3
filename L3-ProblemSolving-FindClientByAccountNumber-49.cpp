#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
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

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

ClientData ConvertLinetoRecord(string Line, string Seperator =
	"#//#")
{
	ClientData Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}



vector <ClientData> LoadCleintsDataFromFile(string FileName)
{
	fstream MyFile;
	vector <ClientData> vClientsInfo;

	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		ClientData Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClientsInfo.push_back(Client);
		}

		MyFile.close();
	}
	return vClientsInfo;
}

void PrintAccountInfo(ClientData Client)
{
	cout << "The Following are the Client details : \n";
	cout << "Account Number: " << Client.AccountNumber << "\n";
	cout << "Pin code      : " << Client.PinCode << "\n";
	cout << "Name          : " << Client.Name << "\n";
	cout << "Phone         : " << Client.Phone << "\n";
	cout << "Account Balance: " << Client.AccountBalance << "\n";
}

bool CheckClient(string AccountNumber,vector <ClientData> vClients,ClientData &ClientRecieve)
{
	
	for (ClientData Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			ClientRecieve = Client;
			return true;
		}
	}
	return false;
	
}


int main()
{
	string AccountNumber;
	cout << "Please enter the AccountNumber To Search?\n";
	cin >> AccountNumber;
	ClientData Client;
	vector <ClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);
	if (CheckClient(AccountNumber, vClients,Client))
	{
		PrintAccountInfo(Client);
	}
	else
	{
		cout << "Client With AccountNumber (" << AccountNumber << ") Not Found!\n";
	}
	system("pause>0");
	return 0;
}
