#include "../stdafx.h"
#include "Chapter_8_Functions.h"
const int arsize = 30;

struct candybar
{
	char producer[arsize] = "Placeholder name";
	double weight = NULL;
	int calories = NULL;
};

void candybarsetter(candybar & bar, char* givenproducer="Millenium munch", double givenweight=2.85, int givencalories=350);


int Chapter_8_Assignment2()
{
	candybar Mars;
	std::cout << "\t\tMars initiated via structure default parameters:"
		<< "\nProducer: \t" << Mars.producer
		<< "\nWeight: \t" << Mars.weight
		<< "\nCalories:\t" << Mars.calories << std::endl;
	candybarsetter(Mars);
	std::cout << "\nDefault setter set Mars values to:\n"
		<< "\nProducer: \t" << Mars.producer
		<< "\nWeight: \t" << Mars.weight
		<< "\nCalories:\t" << Mars.calories << std::endl;
	candybarsetter(Mars, "Mars Inc.", 3.76, 300);
	std::cout << "\n\t\tMars:"
		<< "\nProducer: \t" << Mars.producer
		<< "\nWeight: \t" << Mars.weight
		<< "\nCalories:\t" << Mars.calories << std::endl;
	std::cout << "Press any key to exit ..." << std::endl;
	_getch();
	return 0;
}

void candybarsetter(candybar& bar, char* givenproducer, double givenweight, int givencalories)
{
	for (int i = 0; i < arsize; i++)
	{
		if ('\0' != givenproducer[i])	bar.producer[i] = givenproducer[i]; else bar.producer[i] = '\0';
	};
	bar.weight = givenweight;
	bar.calories = givencalories;
	return;
};

//date of creation: 05.08.2017
//Created by: Marcin Nowak