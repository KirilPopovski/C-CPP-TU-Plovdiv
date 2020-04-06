#include"HashTable.h"
#include"LexicalUnit.h"

int HashTable::Hash(string name) {
	int index = 0;
	for (char& c : name) {
		index += c;
	}
	if (index > 127)
	{
		index %= 128;
	}
	return index;
}
int HashTable::Add(LexicalUnit& lu)
{
	this->table[this->Hash(lu.GetIdentifier())] = lu;
	return 1;
}

int HashTable::Delete(string identifier)
{
	this->table[this->Hash(identifier)] = *new LexicalUnit();
	return 1;
}

int HashTable::Search(string identifier)
{
	return this->Hash(identifier);
}

void HashTable::Print()
{
	for (int i = 0; i < 128; i++)
	{
		if (!this->table[i].GetIdentifier().empty())
		{
			this->table[i].Print();
		}
	}
}