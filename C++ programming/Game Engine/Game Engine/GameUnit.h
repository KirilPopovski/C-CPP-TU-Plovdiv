#pragma once
#include"TPoint.h";

class GameUnit {
	TPoint Position;
	TPoint Target;
	int Condition;
	int MoveSpeed;
	int AttackSpeed;
};
