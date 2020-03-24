#include <iostream>
#include"LexicalUnit.h"
#include"Descriptors.h"
int LexicalUnit::newAddress = 0;
int LexicalUnit::newNumber = 1;

int main()
{
    Descriptors d;
    d.Add(*new LexicalUnit("i1", "int"));
    d.Add(*new LexicalUnit("i2", "char"));
    d.Add(*new LexicalUnit("i3", "float"));
    d.Add(*new LexicalUnit("i4", "int"));
    d.Add(*new LexicalUnit("i5", "double"));

    d.Print();
    return 0;
}

