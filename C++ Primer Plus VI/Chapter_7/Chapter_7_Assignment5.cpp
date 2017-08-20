#include "../stdafx.h"
#include "Chapter_7_Functions.h"

int factorial(int);

int Chapter_7_Assignment5()
{
	std::cout << "Assignment 5 :\n" << std::endl;
	std::cout << "Input number you wish to see factorial of, input any letter/character to end:\n";
	int num = 0;
	while (std::cin >> num)
	{
		std::cout << num << "!=" << factorial(num)
			<< "\nInput another number: ";
	};
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}

int factorial(int number)
{
	if (0 != number) { return factorial(number-1)*number; }
	else{return 1;};
}

//date of creation: 28.07.2017
//Created by: Marcin Nowak