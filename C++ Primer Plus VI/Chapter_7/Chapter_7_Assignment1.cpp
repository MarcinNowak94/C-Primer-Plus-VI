#include "../stdafx.h"
#include "Chapter_7_Functions.h"

const int numofelements = 10;

double Harmonic_Mean(double, double);

int Chapter_7_Assignment1()
{
	std::cout << "Assignment 1 :\n" << std::endl;
	double table[numofelements][1]{};
	int i = 0;
	do
	{
		std::cout << "\n(set " << i << ")Input number 1:";
		std::cin >> table[i][0];
		std::cout << "(set " << i << ")Input number 2:";
		std::cin >> table[i][1];
		i++;
	} while (0 != table[i - 1][0] && 0 != table[i - 1][1]);
	for (int j = 0; j < i - 1; j++)
	{
		std::cout << "Harmonic mean of " << j << " equals: " << Harmonic_Mean(table[j][0], table[j][1]) << std::endl;
	};
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}

double Harmonic_Mean(double number1, double number2)
{
	;
	return (2.0*number1*number2 / (number1 + number2));
};

//date of creation: 28.07.2017
//Created by: Marcin Nowak