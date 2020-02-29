#include<TFibonacci.h>
using namespace Fibonacci;
TFibonacci::TFibonacci()
{
	this->f1 = 1;
	this->f2 = 1;
}

int TFibonacci::Get() {
	int temp = f1 + f2;
	f1 = f2;
	f2 = temp;
	return temp;
}

int TFibonacci::Set(int number)
{
	int p = 1, q = 1, next;
	for (int i = 0; i < 50; i++)
	{
		if (q > number)
		{
			break;
		}
		next = p + q;
		p = q;
		q = next;
	}
	f1 = q;
	f2 = p + q;
	return p + q;
}