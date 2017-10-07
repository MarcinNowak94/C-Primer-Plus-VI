#include "../../stdafx.h"
#include "../Chapter_12_Functions.h"
#include "Cow.h"

int Chapter_12_Assignment1()
{
	std::cout << "\n\aNothing to see here (YET). Move along.";
	std::cout << "\nPress any key to continue ...";
	_getch();
	return 0;
};

/*
1. Consider the following class declaration :
	class Cow 
{
	char name[20];
	char * hobby;
	double weight;
	public: Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow c&);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const;  // display all cow data
};
 Provide the implementation for this class and write a short program that uses all the
 member functions.
*/