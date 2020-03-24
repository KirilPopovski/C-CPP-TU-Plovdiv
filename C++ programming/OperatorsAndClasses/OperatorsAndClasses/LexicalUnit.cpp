#include"LexicalUnit.h"
#include <iostream>
using namespace std;

void LexicalUnit::SetAddress(string type)
{
	this->address = newAddress;
	int size = 0;
	if (this->type == "int")
	{
		size = 2;
	}
	if (this->type == "char")
	{
		size = 1;
	}
	if (this->type == "float")
	{
		size = 4;
	}
	if (this->type == "double")
	{
		size = 8;
	}
	this->newAddress += size;
}

void LexicalUnit::SetDescriptor()
{
	this->descriptor = "V" + this->newNumber;
	this->newNumber++;
}

LexicalUnit::LexicalUnit()
{

}

LexicalUnit::LexicalUnit(string identifier, string type)
{
	this->identifier = identifier;
	this->type = type;
	this->SetAddress(type);
	this->SetDescriptor();
}

void LexicalUnit::operator=(LexicalUnit& lu)
{
	this->address = lu.address;
	this->descriptor = lu.descriptor;
	this->type = lu.type;
	this->identifier = lu.identifier;
}

//LexicalUnit::~LexicalUnit()
//{
//
//}

string LexicalUnit::GetIdentifier()
{
	return this->identifier;
}

void LexicalUnit::Print()
{
	cout << this->identifier << "\t" << this->type << "\t" << this->descriptor << "\t" << this->address << endl;
}