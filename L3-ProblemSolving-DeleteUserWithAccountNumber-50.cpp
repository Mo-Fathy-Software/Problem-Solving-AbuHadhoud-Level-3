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
	bool MarkForDelete = false;
};

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Please enter the AccountNumber to Delete?\n";
	cin >> AccountNumber;
	return AccountNumber;
}

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

string ConvertRecordtoLine(ClientData Client, string Seperator ="#//#")
{
	string Line = "";
	Line += Client.AccountNumber + Seperator;
	Line += Client.PinCode + Seperator;
	Line += Client.Name + Seperator;
	Line += Client.Phone + Seperator;
	Line += to_string(Client.AccountBalance);
	return Line;
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

void PrintClientCard (ClientData Client)
{
	cout << "The Following are the Client details : \n";
	cout << "Account Number: " << Client.AccountNumber << "\n";
	cout << "Pin code      : " << Client.PinCode << "\n";
	cout << "Name          : " << Client.Name << "\n";
	cout << "Phone         : " << Client.Phone << "\n";
	cout << "Account Balance: " << Client.AccountBalance << "\n";
}

bool FindClientByAccountNumber(string AccountNumber,vector <ClientData> vClient,ClientData & Client)
{
	for (ClientData C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <ClientData>& vClients)
{

	for (ClientData & Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			Client.MarkForDelete = true;
			return true;
		}
	}
	return false;

}

vector <ClientData> SaveClientsDataToFile(string FileName, vector <ClientData> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string DataLine;
	if (MyFile.is_open())
	{
		for (ClientData C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				DataLine = ConvertRecordtoLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <ClientData>& vClients)
{
	char Answar = 'n';
	ClientData sClient;
	if (FindClientByAccountNumber(AccountNumber, vClients, sClient))
	{
		PrintClientCard(sClient);
		cout << "Are you sure ,You want to delete Client [y/n] ?\n";
		cin >> Answar;
		if (Answar == 'y' || Answar == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);
			vClients = LoadCleintsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;

		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is not found!";
		return false;
	}
}
int main()
{
	vector <ClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
	system("pause>0");
	return 0;
}