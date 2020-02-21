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

int main()
{
	ClientBank Clients[2];
	char fname[] = "Ivan";
	char lname[] = "Petrov";
	char IBAN1[] = "SB172ZBN010E651";
	char IBAN2[] = "SB172ZBN010E65111";
	Clients[0] = ClientBank(fname, lname, 1);
	char fsname[] = "Peter";
	char lsname[] = "Parker";
	Clients[1] = ClientBank(fsname, lsname, 2);
	Account cl1;
	cl1.type = Paying;
	strcpy_s(cl1.IBAN, IBAN1);
	cl1.current = 100;

	Clients[0].AddAccount(cl1);

	Account cl2;
	cl2.type = Debit;
	strcpy_s(cl2.IBAN, IBAN2);
	cl2.current = 1000;
	Clients[1].AddAccount(cl2);

	int x = Clients[0].AddSumToAccount(200, "SB172ZBN010E651");
	int y = Clients[1].AddSumToAccount(400, "SB172ZBN010E65111");
	
	Clients[0].PrintClientData();
	Clients[1].PrintClientData();


	//TODO add private method GenerateIBAN
	//TODO add method to generate Accounts
	//TODO remove this everywhere
}

