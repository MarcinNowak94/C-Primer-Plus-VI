#include "../stdafx.h"
#include "Chapter_10_Functions.h"
#include "Plorg.h"

/*
7.A Betelgeusean plorg has these properties:
Data
A plorg has a name with no more than 19 letters.
A plorg has a contentment index (CI),which is an integer.

Operations
A new plorg starts out with a name and a CI of 50.
A plorg’s CI can change.
A plorg can report its name and CI.

The default plorg has the name "Plorga".

Write a Plorg class declaration (including data members and member function prototypes)
that represents a plorg.Write the function definitions for the member functions.
Write a short program that demonstrates all the features of the Plorg class.
*/


int Chapter_10_Assignment7()
{
	Plorg George("George", 45);
	George.Display();
	std::cout << "\n";
	George.updateCI();
	George.Display();
	std::cout << "\nRenaming George to Jim, updating CI to 30 (he preferred his previous name):\n";
	George.Report("Jim", 30);
	George.Display();
	std::cout << "\nJim is up to something ...\n";
	George.~Plorg();
	_getch();
	return 0;
};

//date of creation: 26.08.2017
//Created by: Marcin Nowak