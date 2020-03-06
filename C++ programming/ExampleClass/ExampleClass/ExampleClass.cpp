#include<iostream>
#include"Customer.h"
using namespace std;
using namespace CustomerSpace;

int main()
{
	Customer customer(2000);
	Product product;
	product.barcode = "testBarcode";
	product.name = "test1";
	product.price = 123;
	product.useBefore = "21.3.2020";
	product.weight = 5;
	customer.AddProduct(product);
	cout << "Price: " << customer.CalculateAllPrice() << endl;
	cout << "Weight: " << customer.CalculateAllWeights() << endl;
	cout << "HasMoney: " << customer.HasEnoughMoney() << endl;
	return 0;
}

