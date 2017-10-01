#include <random>

#ifndef RANDOM_H
#define RANDOM_H

template<class T1=int>
T1 random(T1 min = 0, T1 max = 100)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(mt);
};

//TODO: Specification for real numbers

#endif // !RANDOM_H
