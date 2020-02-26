#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <iostream>


enum TypeOfAccount
{
	Paying = 1,
	Debit = 2,
	Credit = 3
};

using namespace std;
struct Account {
	TypeOfAccount type;
	char IBAN[23];
	double current;
};

class ClientBank {
	char fName[12];
	char lName[12];
	int countOfAccounts;
	int clientNumber;
	Account account[10];
public:
	ClientBank()
	{
		this->countOfAccounts = 0;
	}
	ClientBank(char* fname, char* lname, int clientNumber)
	{
		this->countOfAccounts = 0;
		strcpy_s(fName, fname);
		strcpy_s(lName, lname);
		this->clientNumber = clientNumber;
	}
	int AddAccount(Account account);
	int RemoveAccount(string IBAN);
	Account* GetByIBAN(string IBAN);
	int AddSumToAccount(double sum, string IBAN);
	double GetTotalSum();
	void PrintClientData();
	int GetClientNumber();
};

int ClientBank::AddAccount(Account account)
{
	if (this->countOfAccounts < 10)
	{
		this->account[this->countOfAccounts] = account;
		this->countOfAccounts++;
		return 1;
	}
	else
	{
		return 0;
	}
}

int ClientBank::RemoveAccount(string IBAN)
{
	int i;
	for (i = 0; i < this->countOfAccounts; i++)
	{
		if (this->account[i].IBAN == IBAN)
		{
			break;
		}
	}
	if (i < this->countOfAccounts)
	{
		for (; i < this->countOfAccounts - 1; i++)
		{
			this->account[i] = this->account[i + 1];
		}
		countOfAccounts--;
		return 1;
	}
	else
	{
		return 0;
	}
}



Account* ClientBank::GetByIBAN(string IBAN)
{
	for (int i = 0; i < this->countOfAccounts; i++)
	{
		if (this->account[i].IBAN == IBAN)
		{
			return &this->account[i];
		}
	}
	return NULL;
}

int ClientBank::AddSumToAccount(double sum, string IBAN)
{
	int i;
	for (i = 0; i < this->countOfAccounts; i++)
	{
		if (this->account[i].IBAN == IBAN)
		{
			break;
		}
	}
	if (i < this->countOfAccounts)
	{
		this->account[i].current += sum;
		return 1;
	}
	else
	{
		return 0;
	}
}

double ClientBank::GetTotalSum()
{
	double sum = 0;
	for (int i = 0; i < this->countOfAccounts; i++)
	{
		sum += this->account[i].current;
	}
	return sum;
}

void ClientBank::PrintClientData()
{
	cout << "Name: " << this->fName << endl;
	cout << "Last name: " << this->lName << endl;
	for (int i = 0; i < this->countOfAccounts; i++)
	{
		cout << "\tType: " << this->account[i].type << endl;
		cout << "\tIBAN: " << this->account[i].IBAN << endl;
		cout << "\tBalance:" << this->account[i].current << endl;
		cout << "\n";
	}
}

int ClientBank::GetClientNumber() {
	return this->clientNumber;
}

class Bank {
	ClientBank* Table;
	int tableEnd;
	int tableSize;
public:
	Bank()
	{
		tableEnd = 0;
		tableSize = 1;
		Table = (ClientBank*)malloc(sizeof(ClientBank) * tableSize);
	}
	Bank(int size)
	{
		tableEnd = 0;
		tableSize = size;
		Table = (ClientBank*)malloc(sizeof(ClientBank) * tableSize);
	}
	~Bank()
	{
		free(Table);
	}
	int AddClient(ClientBank* client);
	int RemoveClient(int clientNumber);
	void PrintClients();
};

int Bank::AddClient(ClientBank* client)
{
	if (tableEnd == tableSize)
	{
		ClientBank* table;
		tableSize *= 2;
		table = Table;
		Table = (ClientBank*)malloc(sizeof(ClientBank) * tableSize);
		memcpy(Table, table, sizeof(ClientBank) * tableSize / 2);
		free(table);
	}
	memcpy(&Table[tableEnd], client, sizeof(ClientBank));
	tableEnd++;
	return 1;
}

int Bank::RemoveClient(int clientNumber)
{
	int i;
	for (i = 0; i < tableEnd; i++)
	{
		if (Table[i].GetClientNumber() == clientNumber)
		{
			break;
		}
	}
	if (i < tableEnd)
	{
		for (; i < tableEnd - 1; i++)
		{
			Table[i] = Table[i + 1];
		}
		tableEnd--;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Bank::PrintClients()
{
	for (int i = 0; i < tableEnd; i++)
	{
		Table[i].PrintClientData();
	}
}



int main()
{
	Bank bank(2);
	char name[20] = "Kircho";
	char family[30] = "Popovski";
	char iban[23] = "Test";
	for (int i = 0; i < 6; i++)
	{
		Account account;
		account.type = Paying;
		strcpy_s(account.IBAN, iban);
		account.current = 250 + i;
		ClientBank client = ClientBank(name, family, i);
		client.AddAccount(account);
		bank.AddClient(&client);
	}
	int result = bank.RemoveClient(3);
	cout << result << endl;
	bank.PrintClients();
	bank.~Bank();
	return 0;

	//TODO add method for random char[] generation
}

