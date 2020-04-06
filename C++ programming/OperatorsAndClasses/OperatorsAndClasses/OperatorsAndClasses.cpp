#include <iostream>
#include<fstream>
#include<windows.data.json.h>
#include<cstdlib>
#include"LexicalUnit.h"
#include"Descriptors.h"
#include"HashTable.h"
int LexicalUnit::newAddress = 0;
int LexicalUnit::newNumber = 1;

using namespace std;

int main()
{
    HashTable d;
    ifstream myfile;
    myfile.open("objects.txt", ios::out);
    string line, identifier, type;
    while (!myfile.eof())
    {
        myfile >> line;
        identifier = line.substr(0, line.find("-"));
        line.erase(0, line.find("-") + 1);
        type = line;
        d.Add(*new LexicalUnit(identifier, type));
    }
    myfile.close();

    d.Delete("i4");

    cout << d.Search("i3") << endl;

    d.Print();
    return 0;
}

