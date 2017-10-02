#include "../../stdafx.h"
#include "../Chapter_11_Functions.h"
#include "stonewt.h"

int Chapter_11_Assignment5()
{
	Stonewt total;
	Stonewt weight1(60);
	Stonewt weight2(6, 10);
	Stonewt weight3(60, 2.76);
	std::cout << "Weight1: " << weight1
		<< "Weight2: " << weight2
		<< "Weight3: " << weight3
		<< "----------------------------------------------\n"
		<< "Total: " << total;
	total = total + weight1;
	std::cout << "Total + weight1 = " << total;
	total = total * weight2;
	std::cout << "Total * weight2 = " << total;
	total = total - weight3;
	std::cout << "Total - weight3 = " << total;
	std::cout << "\nPress any key to exit ...";
	_getch();
	return 0;
};

/*
5. Rewrite the Stonewt class (Listings 11.16 and 11.17) so that it has a state member
that governs whether the object is interpreted in stone form,integer pounds form,
or floating-point pounds form.Overload the << operator to replace the
show_stn() and show_lbs() methods.Overload the addition,subtraction,and
multiplication operators so that one can add,subtract,and multiply Stonewt values.
Test your class with a short program that uses all the class methods and friends.
*/