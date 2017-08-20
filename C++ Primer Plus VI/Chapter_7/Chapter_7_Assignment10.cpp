#include "../stdafx.h"
#include "Chapter_7_Functions.h"

const int amountoffunctions = 4;	//if function is added increment and add to functionpointer list
double add(double x, double y);
double calculate(double a, double b, double function(double, double));
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

int Chapter_7_Assignment10()
{
	std::cout << "Assignment 10 :\n" << std::endl;
	double q = calculate(2.5, 10.4, add);
	std::cout << q << std::endl;
	char question = ' ';
	double a=0, b=0;

	double(*functionpointer[amountoffunctions])(double, double) = { add, subtract, multiply, divide };

	while (question != 'n' )
	{
		std::cout << "\nInput number A:";
		std::cin >> a;
		std::cout << "Input number B:";
		std::cin >> b;
		for (int i = 0; i < amountoffunctions; i++)
		{
			std::cout << calculate(a, b, (*functionpointer[i])) << std::endl;
		}
		std::cout << "\nDo you want to calculate another numbers? [y/n]:";
		std::cin >> question;
	}

	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}

double add(double x, double y)
{
	std::cout << x << "+" << y << "=";
	return x + y;
};

double subtract(double x, double y)
{
	std::cout << x << "-" << y << "=";
	return x - y;
};

double multiply(double x, double y)
{
	std::cout << x << "*" << y << "=";
	return x*y;
};

double divide(double x, double y)
{
	std::cout << x << "/" << y << "=";
	return x / y;
};

double calculate(double a, double b, double function(double, double))
{
	return(function(a, b));
};

//date of creation: 28.07.2017
//Created by: Marcin Nowak