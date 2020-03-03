#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <iostream>
#include<TypeOfAccount.h>
#include<Account.h>
#include<ClientBank.h>
#include<Bank.h>

using namespace std;
using namespace BankSpace;

void genRandom(int length, char symbol, char* address)
{
string value = string(length, symbol);
strcpy_s(address, length, &value[0]);
}

int main()
{
	Bank bank(1);
	char name[20] = "Kircho";
	char family[30] = "Popovski";
	char iban[23] = "Test";
	for (int i = 0; i < 20; i++)
	{
		Account account;
		account.type = Paying;
		//genRandom(22, 'A', iban);
		strcpy_s(account.IBAN, iban);
		account.current = 250;
		ClientBank client = ClientBank(name, family, i);
		client.AddAccount(account);
		bank.AddClient(&client);
		if (i > 10)
		{
			strcpy_s(name, "SecondTest");
			strcpy_s(family, "SecTest");
			strcpy_s(iban, "Test222");
		}
	}

	int result = bank.RemoveClient(2);
	cout << result << endl;
	bank.PrintClients();
	return 0;
}	


	
	