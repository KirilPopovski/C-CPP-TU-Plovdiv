#pragma once
#include<Rober.h>
namespace BandSpace {
	class Band {
		Rober robers[10];
		int bandSize;
		double canRobe;
		double amountRobed;
	public:
		void CalculateRobingCapacity();
		Band();
		~Band();
		int Add(Rober rober);
		int PutInPrison();
		int Robe();
		void Print();
	};

}
