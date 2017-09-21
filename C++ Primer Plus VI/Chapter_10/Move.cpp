#include "../stdafx.h"
#include "Move.h"

Move::Move(double a, double b)
{
	this->x = a;
	this->y = b;
	return;
};

void Move::Showmove() const
{
	std::cout << "\nObject " << this
		<< "\nx=" << this->x
		<< "\ny=" << this->y;
	return;
};

Move Move::add(const Move & m) const
{
	return Move(this->x + m.x, this->y + m.y);
};

void Move::reset(double a, double b)
{
	this->x = a;
	this->y = b;
};
