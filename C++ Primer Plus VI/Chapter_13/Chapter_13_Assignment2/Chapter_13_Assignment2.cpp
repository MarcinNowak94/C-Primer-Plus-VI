#include "../../stdafx.h"
#include "../Chapter_13_Functions.h"

using namespace std;
#include "classic2.h" // which will contain #include cd.h
using namespace Cd2;


void Bravo(const Cd & disk);

int Chapter_13_Assignment2()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report();    // use Cd method
	c2.Report();    // use Classic method

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();  // use Cd method for cd object
	pcd = &c2;
	pcd->Report();  // use Classic method for classic object

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();

	std::cout << "Press any key to continue ...\n";
	_getch();
	return 0;
};

void Bravo(const Cd & disk)
{
	disk.Report();
};

//date of creation: 26.11.2017
//Created by: Marcin Nowak

/*
Do Programming Exercise 1 but use dynamic memory allocation instead of fixed
size arrays for the various strings tracked by the two classes
*/