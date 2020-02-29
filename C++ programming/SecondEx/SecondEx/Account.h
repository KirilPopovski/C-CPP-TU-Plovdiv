#pragma once
#include<TypeOfAccount.h>
struct Account {
	TypeOfAccount type;
	char IBAN[23];
	double current;
};
