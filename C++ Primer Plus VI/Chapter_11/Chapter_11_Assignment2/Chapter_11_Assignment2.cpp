#include "../../stdafx.h"
#include "../Chapter_11_Functions.h"
#include "vect_2.h"

int Chapter_11_Assignment2()
{
		using namespace std;
		using VECTOR_2::Vector;
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
};

/*
2. Modify the Vector class header and implementation files (Listings 11.13 and 11.14)
so that the magnitude and angle are no longer stored as data components.Instead,
they should be calculated on demand when the magval() and angval() methods
are called.You should leave the public interface unchanged (the same public methods
with the same arguments) but alter the private section,including some of the
private method and the method implementations.Test the modified version with
Listing 11.15,which should be left unchanged because the public interface of
the Vector class is unchanged.
*/