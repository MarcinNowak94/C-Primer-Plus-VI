#include "../../stdafx.h"
#include "../Chapter_11_Functions.h"
#include "vect.h"

int Chapter_11_Assignment1()
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
	std::ofstream outfile;
	outfile.open("Chapter_11/Chapter_11_Assignment1/randomwalker.txt");
	cout << "Podaj dystans do przejœcia (k, aby zakoñczyæ): ";
	while (cin >> target)
	{
		cout << "Podaj d³ugoœæ kroku: ";
		if (!(cin >> dstep))
			break;
		outfile << "Target Distance:\t" << target
			<< ", Step Size: " << dstep;
		while (result.magval() < target)
		{
			outfile << "\n" << steps << ": " << result;
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
		outfile << "\nAfter " << steps << " steps, the subject has the following location :\n";
		result.rect_mode();
		outfile << result
			<< "\nor\n";
		result.polar_mode();
		outfile << result
			<< "\nAverage outward distance per step = " << result.magval() / steps << std::endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Podaj dystans do przejœcia (k, aby zakoñczyæ): ";
	}
	cout << "Koniec!\n";
	outfile.close();
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
	_getch();
	return 0;
};


/*
1. Modify Listing 11.15 so that it writes the successive locations of the random walker
into a file.Label each position with the step number.Also have the program write
the initial conditions (target distance and step size) and the summarized results to
the file.The file contents might look like this:
Target Distance: 100, Step Size: 20
0: (x,y) = (0, 0)
1: (x,y) = (-11.4715, 16.383)
2: (x,y) = (-8.68807, -3.42232)
...
26: (x,y) = (42.2919, -78.2594)
27: (x,y) = (58.6749, -89.7309)
After 27 steps, the subject has the following location:
(x,y) = (58.6749, -89.7309)
or
(m,a) = (107.212, -56.8194)
Average outward distance per step = 3.97081
*/
/*
// randwalk.cpp -- test klasy Vector
// kompilowaæ z plikiem vect.cpp
#include <iostream>
#include <cstdlib>    // prototypy funkcji rand() i srand()
#include <ctime>      // prototyp funkcji time()
#include "vect.h"

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
*/