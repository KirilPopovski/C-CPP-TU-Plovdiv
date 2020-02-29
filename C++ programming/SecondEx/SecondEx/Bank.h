#pragma once
#include<ClientBank.h>
#include <TFibonacci.h>
using namespace ClientBankSpace;
using namespace Fibonacci;
namespace BankSpace {
	class Bank {
		ClientBank* Table;
		int tableEnd;
		int tableSize;
		TFibonacci FNumber;
	public:
		Bank();
		Bank(int size);
		~Bank();
		int AddClient(ClientBank* client);
		int RemoveClient(int clientNumber);
		void PrintClients();
	};
}
