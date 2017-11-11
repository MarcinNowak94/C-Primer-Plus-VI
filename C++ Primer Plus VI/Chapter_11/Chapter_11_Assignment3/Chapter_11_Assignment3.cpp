#include "../../stdafx.h"
#include "../Chapter_11_Functions.h"
#include "vect_3.h"
// randwalk.cpp -- test klasy Vector
// kompilowaæ z plikiem vect.cpp
#include <iostream>
#include <cstdlib>    // prototypy funkcji rand() i srand()
#include <ctime>      // prototyp funkcji time()


int Chapter_11_Assignment3()
{
	using namespace std;
	using VECTOR_3::Vector;
	srand(time(0));   // inicjalizacja generatora liczb pseudolosowych
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target = random(100,200);
	double dstep = random<double>(1, target - 1);
	int trials = 0;
	double min = DBL_MAX;
	double max = DBL_MIN;
	double avg = 0;
	std::cout << "Input amount of trials: ";
	std::cin >> trials;
	int i = 0;
	while (i++ < trials)
	{
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		std::cout << "--Trial#" << i <<"\t("<< steps << "steps)\n";
		if (steps < min) min = steps;
		if (steps > max) max = steps;
		avg += steps;
		steps = 0;
		result.reset(0.0, 0.0);
	};
	std::cout << "\nDistance to travel: " << target << ", step size: " << dstep
		<< "\nAverage of " << trials << " trials is: " << avg / trials
		<< "\nMin amount of steps: " << min
		<< "\nMax amount of steps: " << max;
	_getch();
	return 0;
};


/*
3. Modify Listing 11.15 so that instead of reporting the results of a single trial for a
particular target/step combination,it reports the highest,lowest,and average number
of steps for N trials,where N is an integer entered by the user.
*/


