#include "../../stdafx.h"
#include "../Chapter_11_Functions.h"
#include "vect_2.h"

int Chapter_11_Assignment2()
{
	std::cout << "\n\aNothing to see here (YET). Move along.";
	std::cout << "\nPress any key to continue ...";
	_getch();
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