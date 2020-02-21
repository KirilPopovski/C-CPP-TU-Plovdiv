#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <iostream>
#define EOT -1
#define BOT -2
using namespace std;
struct BelRow {
	char Name[12];
	char Fam[15];
	unsigned long Tel;
};
class Bel {
	BelRow Table[100];
	int TableEnd;
	int CurrentRecord;
public:
	Bel(void) {
		this->TableEnd = 0;
		CurrentRecord = 0;
	}
	int Append(char* Name, char* Fam, unsigned long Tel);
	int Append(BelRow* ARow);
	BelRow* FindRowByName(char* Name);
	int First();
	int Next();
	int Prev();
	int Last();
	BelRow* Get();
};

int Bel::First()
{
	this->CurrentRecord = 0;
	return 1;
}

int Bel::Next()
{
	if (this->CurrentRecord < this->TableEnd - 1)
	{
		this->CurrentRecord++;
		return 0;
	}
	else
	{
		return EOT;
	}
}

int Bel::Last()
{
	this->CurrentRecord = this->TableEnd - 1;
	return 1;
}

int Bel::Prev()
{
	if (this->CurrentRecord > 0)
	{
		this->CurrentRecord--;
		return 0;
	}
	else
	{
		return BOT;
	}
}

BelRow* Bel::Get() 
{
	return &this->Table[this->TableEnd];
}

int Bel::Append(char* Name, char* Fam, unsigned long Tel)
{
	if (this->TableEnd >= 100) 
	{
		return 0;
	}
	strcpy_s(this->Table[this->TableEnd].Name, Name);
	strcpy_s(this->Table[this->TableEnd].Fam, Fam);
	this->Table[TableEnd].Tel = Tel;
	this->TableEnd++;
	return 1;
}

int Bel::Append(BelRow* ARow)
{
	if (this->TableEnd >= 100)
	{
		return 0;
	}
	memcpy(&this->Table[TableEnd], ARow, sizeof(BelRow));
	this->TableEnd++;
	return 1;
}

BelRow* Bel::FindRowByName(char* Name)
{
	for (int i = 0; i < this->TableEnd; i++)
	{
		if (!strcmp(this->Table[i].Name, Name))
		{
			return &this->Table[i];
		}
	}
	return NULL;
}

int main()
{
	int x, y;
	Bel Tef1, Tef2;
	char fname[] = "Ivan";
	char lname[] = "Petrov";
	x = Tef1.Append(fname, lname, 8657L);
	char fsname[] = "Stefan";
	char lsname[] = "Stojanov";
	y = Tef2.Append(fsname, lsname, 8877);
	Tef2.Append(Tef1.FindRowByName(fname));
	BelRow* ARow = Tef2.FindRowByName(fname);
	if (ARow)
	{
		cout << "Name:" << ARow->Name << "\n" << "Fam:" << ARow->Fam << "\n" << "Tel:" << ARow->Tel << endl;
	}
	return 0;
}
