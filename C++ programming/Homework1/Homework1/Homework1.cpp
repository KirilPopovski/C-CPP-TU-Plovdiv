#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <iostream>

using namespace std;

enum OS {
	Android = 1,
	IOS = 2,
	Windows = 3
};

class Smartphone {
	char model[21];
	double price;
	OS os;
public:
	Smartphone()
	{

	}
	Smartphone(char* model, double price, OS os)
	{
		strcpy_s(this->model, model);
		this->price = price;
		this->os = os;
	}
	Smartphone(const Smartphone &old_obj)
	{
		strcpy_s(this->model, old_obj.model);
		this->price = old_obj.price;
		this->os = old_obj.os;
	}
	double GetPrice()
	{
		return this->price;
	}
	void Print()
	{
		cout << "Model: " << this->model << endl;
		cout << "Price: " << this->price << endl;
		cout << "OS: " << this->os << endl;
	}
};

void SortByPrice(Smartphone *phones, int count)
{
	Smartphone swap;
	for (int i = 0; i < count - 1; i++) 
		for (int j = 0; j < count - i - 1; j++)
			if (phones[j].GetPrice() > phones[j + 1].GetPrice())
			{
				swap = phones[j];
				phones[j] = phones[j + 1];
				phones[j + 1] = swap;
			}
}

int main()
{
	Smartphone phones[3];
	char model[] = "Galaxy A70";
	for (int i = 0; i < 3; i++)
	{
		phones[i] = *(new Smartphone(model, (250 - i), Android));
	}
	SortByPrice(phones, 3);
	for (int i = 0; i < 3; i++)
	{
		phones[i].Print();
	}
}
