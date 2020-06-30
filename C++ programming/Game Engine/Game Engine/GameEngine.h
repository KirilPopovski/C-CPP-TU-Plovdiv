#pragma once
#include"GameUnit.h"

class GameEngine {
	GameUnit* units[100];
	int count;
public:
	GameEngine()
	{
		this->count = 0;
	}
	int AddUnit(GameUnit* unit)
	{
		if (count < 100)
		{
			units[count] = unit;
			count++;
		}
	}
};
