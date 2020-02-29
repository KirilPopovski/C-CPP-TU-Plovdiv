#include<ClientBank.h>
#include<Bank.h>
#include <iostream>
using namespace ClientBankSpace;
using namespace BankSpace;

Bank::Bank()
{
	tableEnd = 0;
	tableSize = 1;
	Table = (ClientBank*)malloc(sizeof(ClientBank) * tableSize);
}

Bank::Bank(int size)
{
	tableEnd = 0;
	tableSize = FNumber.Set(size);
	Table = (ClientBank*)malloc(sizeof(ClientBank) * tableSize);
}

Bank::~Bank()
{
	free(Table);
}

int Bank::AddClient(ClientBank* client)
{
	if (tableEnd == tableSize)
	{
		ClientBank* table;
		tableSize = FNumber.Get();
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