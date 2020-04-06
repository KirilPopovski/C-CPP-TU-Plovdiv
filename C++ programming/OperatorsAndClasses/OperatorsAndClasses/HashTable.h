#pragma once
#include"LexicalUnit.h"
class HashTable {
	LexicalUnit table[128];
public:
	int Hash(string name);
	int Add(LexicalUnit& lu);
	int Delete(string identifier);
	int Search(string identifier);

	void Print();
};
