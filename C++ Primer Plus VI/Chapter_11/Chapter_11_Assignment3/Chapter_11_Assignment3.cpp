#include "../../stdafx.h"
#include "../Chapter_11_Functions.h"
#include "vect_3.h"

int Chapter_11_Assignment3()
{
	std::cout << "\n\aNothing to see here (YET). Move along.";
	std::cout << "\nPress any key to continue ...";
	_getch();
	return 0;
};


/*
3. Modify Listing 11.15 so that instead of reporting the results of a single trial for a
particular target/step combination,it reports the highest,lowest,and average number
of steps for N trials,where N is an integer entered by the user.
*/

// randwalk.cpp -- test klasy Vector
// kompilowaæ z plikiem vect.cpp
#include <iostream>
#include <cstdlib>    // prototypy funkcji rand() i srand()
#include <ctime>      // prototyp funkcji time()
#include "vect_3.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));   // inicjalizacja generatora liczb pseudolosowych
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Podaj dystans do przejœcia (k, aby zakoñczyæ): ";
	while (cin >> target)
	{
		cout << "Podaj d³ugoœæ kroku: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "Po " << steps << " krokach delikwent "
			"osi¹gn¹³ po³o¿enie:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " czyli\n" << result << endl;
		cout << "Œrednia d³ugoœæ kroku pozornego = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Podaj dystans do przejœcia (k, aby zakoñczyæ): ";
	}
	cout << "Koniec!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}