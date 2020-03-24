#pragma once
#include"LexicalUnit.h"
class Descriptors {
	LexicalUnit table[100];
	int number;
public:
	Descriptors();
	~Descriptors();
	int Add(LexicalUnit& lu);
	int Delete(string identifier);
	int Search(string identifier);

	void Print();
};
