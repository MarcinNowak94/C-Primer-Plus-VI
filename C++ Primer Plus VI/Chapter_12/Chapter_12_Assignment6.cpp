#include "../stdafx.h"
#include "Chapter_12_Functions.h"


int Chapter_12_Assignment6()
{
	std::cout << "\n\aNothing to see here (YET). Move along.";
	std::cout << "\nPress any key to continue ...";
	_getch();
	return 0;
};

/*
6. The Bank of Heather would like to know what would happen if it added a second
ATM. Modify the simulation in this chapter so that it has two queues.Assume that
a customer will join the first queue if it has fewer people in it than the second
queue and that the customer will join the second queue otherwise.Again,find a
value for number of customers per hour that leads to an average wait time of one
minute.(Note:This is a nonlinear problem in that doubling the number of ATMs
doesn�t double the number of customers who can be handled per hour with a one
minute wait maximum.)
*/