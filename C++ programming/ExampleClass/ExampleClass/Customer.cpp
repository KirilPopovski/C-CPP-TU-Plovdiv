#include"Customer.h"
using namespace CustomerSpace;
using namespace std;

//Customer::Customer()
//{
//	this->cash = 0;
//}

Customer::Customer(double cash = 0)
{
	this->cash = cash;
}

Customer::Customer(const Customer& obj1) {
	this->cash = obj1.cash;
	this->products = obj1.products;
}

int Customer::AddProduct(Product product)
{
	map<Product, int>::iterator it = this->products.find(product);
	if (this->products.end() == it)
	{
		this->products.insert(pair<Product, int>(product, 1));
		return 1;
	}
	map<Product, int>::iterator it2 = this->products.find(product);
	it2->second++;
	return 1;
}

double Customer::CalculateAllWeights() {
	double sum = 0;
	map<Product, int>::iterator it;

	for (it = this->products.begin(); it != products.end(); ++it)
	{
		sum += it->first.weight;
	}
	return sum;
}

double Customer::CalculateAllPrice() {
	double sum = 0;
	map<Product, int>::iterator it;

	for (it = this->products.begin(); it != products.end(); ++it)
	{
		sum += it->first.price;
	}
	return sum;
}

bool Customer::HasEnoughMoney() {
	return this->cash >= this->CalculateAllPrice();
}

int Customer::Pay() {
	if (this->HasEnoughMoney())
	{
		this->cash -= this->CalculateAllPrice();
		return 1;
	}
	return 0;
}

int Customer::RemoveProduct(string nameOfProduct) {
	map<Product, int>::iterator it;

	for (it = this->products.begin(); it != products.end(); ++it)
	{
		if (it->first.name == nameOfProduct)
		{
			this->products.erase(it);
			return 1;
		}
	}
	return 0;
}