#include"Descriptors.h"
#include"LexicalUnit.h"

Descriptors::Descriptors()
{
	this->number = 0;
}

Descriptors::~Descriptors() {

}

int Descriptors::Add(LexicalUnit& lu)
{
	if (number < 100)
	{
		this->table[this->number] = lu;
		this->number++;
		return 1;
	}
	return 0;
}

int Descriptors::Delete(string identifier)
{
	int index = -1;
	for (int i = 0; i < number; i++)
	{
		if (this->table->GetIdentifier() == identifier)
		{
			index = i;
			break;
		}
	}
	if (index > -1)
	{
		for (int i = index; i < number - 1; i++)
		{
			this->table[i] = this->table[i + 1];
		}
		number--;
		return 1;
	}
	else return 0;
}

int Descriptors::Search(string identifier)
{
	int index = -1;
	for (int i = 0; i < number; i++)
	{
		if (table[i].GetIdentifier() == identifier)
		{
			index = i;
			break;
		}
	}
	return index;
}

void Descriptors::Print()
{
	for (int i = 0; i < number; i++)
	{
		table[i].Print();
	}
}