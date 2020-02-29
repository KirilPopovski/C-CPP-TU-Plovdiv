#pragma once
#include<Account.h>
using namespace std;
namespace ClientBankSpace {
	class ClientBank {
		char fName[12];
		char lName[12];
		int countOfAccounts;
		int clientNumber;
		Account account[10];
	public:
		ClientBank();
		ClientBank(char* fname, char* lname, int clientNumber);
		int AddAccount(Account account);
		int RemoveAccount(char* IBAN);
		Account* GetByIBAN(char* IBAN);
		int AddSumToAccount(double sum, char* IBAN);
		double GetTotalSum();
		void PrintClientData();
		int GetClientNumber();
	};
}


