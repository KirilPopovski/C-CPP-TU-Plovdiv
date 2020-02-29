#include<ClientBank.h>
#include<string.h>
#include <iostream>

using namespace ClientBankSpace;
using namespace std;

ClientBank::ClientBank()
{
	this->countOfAccounts = 0;
}

ClientBank::ClientBank(char* fname, char* lname, int clientNumber)
{
	this->countOfAccounts = 0;
	strcpy_s(fName, fname);
	strcpy_s(lName, lname);
	this->clientNumber = clientNumber;
}

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

int ClientBank::RemoveAccount(char* IBAN)
{
	int i;
	for (i = 0; i < this->countOfAccounts; i++)
	{
		if (strcmp(this->account[i].IBAN, IBAN))
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

Account* ClientBank::GetByIBAN(char* IBAN)
{
	for (int i = 0; i < this->countOfAccounts; i++)
	{
		if (strcmp(this->account[i].IBAN, IBAN))
		{
			return &this->account[i];
		}
	}
	return NULL;
}

int ClientBank::AddSumToAccount(double sum, char* IBAN)
{
	int i;
	for (i = 0; i < this->countOfAccounts; i++)
	{
		if (strcmp(this->account[i].IBAN, IBAN))
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
	cout << "Client number:" << this->clientNumber << endl;
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