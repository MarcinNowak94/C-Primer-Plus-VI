#include "../stdafx.h"
#include "Chapter_10_Functions.h"
#include "../Chapter_9/Sales.h"

/*
4. Do Programming Exercise 4 from Chapter 9 but convert the Sales structure and
its associated functions to a class and its methods.Replace the setSales(Sales &, double [], int)
function with a constructor.Implement the interactive setSales(Sales &) method
by using the constructor.Keep the class within the namespace SALES.
*/


int Chapter_10_Assignment4()
{
	std::cout << "\a\nNothing to see here (YET), move along.";
	std::cout << "\nPress any key to contine..." << std::endl;
	double arr[] = { 4000, 57632, 7.89, 875.4 };
	SALES::SALES year1;
	SALES::SALES year2;
	year1.SetSales();
	year1.ShowSales();
	year2.ShowSales();
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return 0;
};

//date of creation: 26.08.2017
//Created by: Marcin Nowak