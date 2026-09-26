#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const string ClientsFileName = "Clients.txt";


struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};



sClient ReadClientData()
{
	sClient Client;
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

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Please enter the Account Number to Search?\n";
	cin >> AccountNumber;
	return AccountNumber;
}


void AddDataLineToFile(string FileName, string DataLine)
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

string ConvertRecordtoLine(sClient Client1)
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

sClient ConvertLinetoRecord(string Line, string Seperator =
	"#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;
}
vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	fstream MyFile;
	vector <sClient> vClientsInfo;

	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClientsInfo.push_back(Client);
		}

		MyFile.close();
	}
	return vClientsInfo;
}
void AddClientData()
{
	cout << "Adding New Client: \n";
	sClient Client = ReadClientData();
	AddDataLineToFile(ClientsFileName, ConvertRecordtoLine(Client));
}
void AddNewClients()
{
	char AddAgain = 'Y';
	do
	{
		system("cls");
		AddClientData();
		cout << "Client Added Succesfully Do you want to Add more Clients? [Y] or [N] \n";
		cin >> AddAgain;
	} while (toupper(AddAgain) == 'Y');
	cout << "\n\n Press any key to go to Main Menue ......";
	system("pause>0");
	void BankMenu();
	void BankSystem();
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}


void PrintAllClientsData(vector <sClient> vClients)
{
	vClients = LoadCleintsDataFromFile(ClientsFileName);
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	for (sClient &Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\n\n Press any key to go to Main Menue ......";
	system("pause>0");
	
}




void PrintClientCard(sClient Client)
{
	cout << "The Following are the Client details : \n";
	cout << "Account Number: " << Client.AccountNumber << "\n";
	cout << "Pin code      : " << Client.PinCode << "\n";
	cout << "Name          : " << Client.Name << "\n";
	cout << "Phone         : " << Client.Phone << "\n";
	cout << "Account Balance: " << Client.AccountBalance << "\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClient, sClient& Client)
{
	for (sClient C : vClient)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}





bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

	for (sClient& Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
		{
			Client.MarkForDelete = true;
			return true;
		}
	}
	return false;

}
vector <sClient> SaveClientsDataToFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string DataLine;
	if (MyFile.is_open())
	{
		for (sClient C : vClients)
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

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	char Answar = 'n';
	sClient sClient;
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


void DeleteClient()
{
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
	cout << "\n\n Press any key to go to Main Menue ......";
	system("pause>0");
	
}





vector <sClient> SaveClientsDataUpdatedToFile(string FileName, vector
	<sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//overwrite
	string DataLine;
	if (MyFile.is_open())
	{
		for (sClient C : vClients)
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

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;
	Client.AccountNumber = AccountNumber;
	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}


bool UpdateClientByAccountNumber(string AccountNumber, vector
	<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients,
		Client))
	{
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want update this client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveClientsDataUpdatedToFile(ClientsFileName, vClients);
			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}

}

void UpdateClient()
{
	vector <sClient> vClients =
		LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
	cout << "\n\n Press any key to go to Main Menue ......";
	system("pause>0");
	
}

void FindClient()
{
	string AccountNumber = ReadAccountNumber();
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	sClient Client;
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is not found!";
	}
	cout << "\n\n Press any key to go to Main Menue ......";
	system("pause>0");
	
}


void BankMenu()
{
	cout << "\n======================================================\n";
	cout << "                  Main Menue Screen                     \n";
	cout << "======================================================\n";
	cout << "      [1] Show Client List. \n";
	cout << "      [2] Add New Client. \n";
	cout << "      [3] Delete Client. \n";
	cout << "      [4] Update Client Info. \n";
	cout << "      [5] Find Client. \n";
	cout << "      [6] Exit. \n";
	cout << "======================================================\n";	
}

bool Exit()
{
	return false;
}

void BankSystem()
{
	vector <sClient> vClients;
	LoadCleintsDataFromFile(ClientsFileName);
	int Choose = 0;
	do
	{
		cout << "Choose What do you want to do [1 to 6] ? ";
		cin >> Choose;
	} while (Choose < 1 || Choose > 6);
	
	switch (Choose)
	{
	case 1 :
		return PrintAllClientsData(vClients);
	case 2 :
		return AddNewClients();
	case 3 :
		return DeleteClient();
	case 4 :
		return UpdateClient();
	case 5 :
		return FindClient();
	case 6 :
		exit(0);
	}

}

int main()
{
	while (true)
	{
		system("cls");
		BankMenu();
		BankSystem();
	}
	
}