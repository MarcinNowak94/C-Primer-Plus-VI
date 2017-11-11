#include <random>

#ifndef RANDOM_H
#define RANDOM_H

template<class T1=int>
T1 random(T1 min = 0, T1 max = 100)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	if (typeid(T1) == typeid(float) || typeid(T1) == typeid(double))
	{
		std::uniform_real_distribution<double> dist(min, max);
		return dist(mt);
	};
	std::uniform_int_distribution<int> dist(min, max);
	return dist(mt);
};

#endif // !RANDOM_H
