#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <iostream>
#include"Band.h"
using namespace std;
using namespace BandSpace;

int main()
{
	Band band;
	char name[20] = "KPopovski";
	for (int i = 0; i < 5; i++)
	{
		Rober rober;
		rober.isInPrison = false;
		strcpy_s(rober.name, name);
		rober.rating = i % 3;
		band.Add(rober);
	}
	band.Print();
	for (int i = 0; i < 5; i++)
	{
		Rober rober;
		rober.isInPrison = false;
		strcpy_s(rober.name, name);
		rober.rating = i % 5;
		band.Robe();
		band.PutInPrison();
		band.Add(rober);
	}
	band.Print();
	return 0;
}