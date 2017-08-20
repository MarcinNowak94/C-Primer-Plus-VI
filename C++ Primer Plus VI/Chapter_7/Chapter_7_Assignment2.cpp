#include "../stdafx.h"
#include "Chapter_7_Functions.h"

const unsigned int arsize = 10;

void Input(unsigned int*);
void Display(unsigned int*);
double Average(unsigned int*);

int Chapter_7_Assignment2()
{
	std::cout << "Assignment 2 :\n" << std::endl;
	unsigned int scores[arsize]{};
	Input(scores);
	Display(scores);
	std::cout << "= average of ~" << Average(scores) << std::endl;
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}

void Input(unsigned int* table)
{
	unsigned int iterator = 0;
	std::cout << "Input #" << iterator << " score: " << std::endl;
	while (std::cin >> (*table) && iterator<arsize-1)
	{
		iterator++; table++;
		std::cout << "Input #" << iterator << " score: " << std::endl;
	};
	return;
};

void Display(unsigned int* tablepointer)
{
	unsigned int iterator = 0;
	std::cout << "\nScores:";
	do
	{
		std::cout << "[" << *(tablepointer+iterator) << "] ";
		iterator++;
	} while (0!=*(tablepointer+iterator) && iterator<arsize-1);
};

double Average(unsigned int* tablepointer)
{
	double average = 0;
	for (unsigned int i = 0; i < arsize-1; i++)
	{
		if (0 != *(tablepointer + i)) (average += *(tablepointer + i)); else return (average / i);
	};
	return (average / (arsize - 1));
};

//date of creation: 28.07.2017
//Created by: Marcin Nowak