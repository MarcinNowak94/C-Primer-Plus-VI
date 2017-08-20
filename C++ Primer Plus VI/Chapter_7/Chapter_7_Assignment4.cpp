#include "../stdafx.h"
#include "Chapter_7_Functions.h"

long double Chance(unsigned int, unsigned int);

int Chapter_7_Assignment4()
{
	std::cout << "Assignment 4 :\n" << std::endl;
	//5 liczb z przedzia³u <1,47>, powerball z <1,27> prawd5*prawdpowerball
	std::cout << "Chance of winning lottery where:\n"
		<< "- You pick 5 numbers from 1 to 47\n"
		<< "- You pick additional number from 1 to 27\n"
		<< "\n\nEquals: 1 in " << Chance(5, 47)*Chance(1, 27) << std::endl;
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}

long double Chance(unsigned int pickednumbers, unsigned int totalamountofnumbers)
{
	long double chances = 1.0;
	for (pickednumbers; pickednumbers > 0; pickednumbers--, totalamountofnumbers--)
	{
		chances = chances*(totalamountofnumbers / pickednumbers);
		std::cout << std::endl;
	};
	return chances;
};

//date of creation: 28.07.2017
//Created by: Marcin Nowak