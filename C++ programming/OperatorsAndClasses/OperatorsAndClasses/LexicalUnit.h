#pragma once
#include <string>
using namespace std;
class LexicalUnit {
	string identifier;
	string type;
	string descriptor;
	int address;
	void SetAddress(string type);
	void SetDescriptor();

public:
	static int newAddress;
	static int newNumber;
	LexicalUnit();
	LexicalUnit(string pIdentifier, string pType);
	void operator=(LexicalUnit& lu);
	//~LexicalUnit();
	string GetIdentifier();
	void Print();
};