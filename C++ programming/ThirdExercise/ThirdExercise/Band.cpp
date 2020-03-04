#include"Band.h"
#include <iostream>
using namespace BandSpace;
using namespace std;
Band::Band() {
	bandSize = 0;
	canRobe = 0;
	amountRobed = 0;
}
int Band::Add(Rober rober)
{
	if (this->bandSize < 10)
	{
		this->robers[bandSize] = rober;
		bandSize++;
		return 1;
	}
	return 0;
}
int Band::PutInPrison()
{
	float maxRating;
	int index;
	if (this->bandSize == 0)
	{
		return 0;
	}
	maxRating = this->robers[0].rating;
	index = 0;
	for (int i = 1; i < this->bandSize; i++)
	{
		if (this->robers[i].rating > this->robers[i - 1].rating)
		{
			maxRating = this->robers[i].rating;
			index = i;
		}
	}
	this->robers[index].isInPrison = true;
	return 1;
}

void Band::CalculateRobingCapacity()
{
	for (int i = 0; i < this->bandSize; i++)
	{
		if (!this->robers[i].isInPrison)
		{
			this->canRobe += (this->robers[i].rating * 0.8);
		}
	}
}

int Band::Robe() {
	this->CalculateRobingCapacity();
	this->amountRobed += this->canRobe;
	return 1;
}

Band::~Band()
{
	free(this->robers);
}

void Band::Print()
{
	cout << "Total: " << this->amountRobed << endl;
	cout << "Capacity" << this->canRobe << endl;
	for (int i = 0; i < this->bandSize; i++)
	{
		cout << "\tName: " << this->robers[i].name << endl;
		cout << "\tRating: " << this->robers[i].rating << endl;
		cout << "\tIs in prison: " << this->robers[i].isInPrison << endl;
	}
}
