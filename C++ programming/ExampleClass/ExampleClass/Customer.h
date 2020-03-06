#pragma once
#include "Product.cpp"
#include<map>
using namespace std;
namespace CustomerSpace {
	class Customer {
		map<Product, int> products;
		double cash;
	public:
		//Customer();
		Customer(double cash);
		Customer(const Customer& obj1);
		int AddProduct(Product product);
		double CalculateAllWeights();
		double CalculateAllPrice();
		bool HasEnoughMoney();
		int Pay();
		int RemoveProduct(string nameOfProduct);
	};
}
