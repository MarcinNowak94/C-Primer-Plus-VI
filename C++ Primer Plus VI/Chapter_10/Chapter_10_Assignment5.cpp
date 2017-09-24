#include "../stdafx.h"
#include "Chapter_10_Functions.h"
#include "stack.h"

/*
5. Consider the following structure declaration:
struct customer
{
char fullname[35];
double payment;
};
Write a program that adds and removes customer structures from a stack,represented by
a Stack class declaration.Each time a customer is removed,his or her payment
should be added to a running total,and the running total should be reported.
Note:You should be able to use the Stack class unaltered;just change
the typedef declaration so that Item is type customer instead of unsigned long.
*/

int Chapter_10_Assignment5()
{
	//std::cout << "\a\nNothing to see here (YET), move along.";
	//std::cout << "\nPress any key to contine..." << std::endl;
	long double runningtotal = 0;
	Stack stack;
	customer customertab[]=
	{
		{"Customer 1", 350},
		{"Customer 2", 450},
		{"Customer 3", 10},
		{"George", 2.56}
	};
	for (size_t i = 0; i < (sizeof(customertab)/sizeof(customertab[0])); i++)
	{
		stack.push(customertab[i]);
	};
	for (size_t i = (sizeof(customertab) / sizeof(customertab[0]))-1; !stack.isempty(); i--)
	{
		runningtotal += customertab[i].payment;
		stack.pop(customertab[i]);
		std::cout << "\nRunning total =" << runningtotal;
	};
	_getch();
	return 0;
};

//date of creation: 26.08.2017
//Created by: Marcin Nowak