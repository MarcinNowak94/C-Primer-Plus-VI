#include "../../stdafx.h"
#include "../Chapter_11_Functions.h"
#include "mytime3.h"

int Chapter_11_Assignment4()
{
	using std::cout;
	using std::endl;
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida i Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;           // operator+()
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;            // metoda operator*()
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10 * Tosca: " << 10.0 * tosca << endl;
	_getch();
	return 0;
};


/*
4. Rewrite the final Time class example(Listings 11.10, 11.11, and 11.12) so that all
the overloaded operators are implemented using friend functions.
*/