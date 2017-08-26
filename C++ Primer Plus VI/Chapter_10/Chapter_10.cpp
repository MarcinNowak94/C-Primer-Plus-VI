 #include "Chapter_10_Functions.h" 
#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"

int Chapter_10_Assignment1(); //TODO: Chapter_10_Assignment1
int Chapter_10_Assignment2(); //TODO: Chapter_10_Assignment2	
int Chapter_10_Assignment3(); //TODO: Chapter_10_Assignment3
int Chapter_10_Assignment4(); //TODO: Chapter_10_Assignment4
int Chapter_10_Assignment5(); //TODO: Chapter_10_Assignment5
int Chapter_10_Assignment6(); //TODO: Chapter_10_Assignment6
int Chapter_10_Assignment7(); //TODO: Chapter_10_Assignment7
int Chapter_10_Assignment8(); //TODO: Chapter_10_Assignment8


int Chapter_10()
{
	std::string options[]
	{
		"Assignment 1:\t",
		"Assignment 2:\t",
		"Assignment 3:\t",
		"Assignment 4:\t",
		"Assignment 5:\t",
		"Assignment 6:\t",
		"Assignment 7:\t",
		"Assignment 8:\t",
		"Back"
	};
	const int amountofoptions = 9;
	int input;
	do
	{
		input = simplemenu(options, amountofoptions);
		switch (input)
		{
		case 0: Chapter_10_Assignment1(); break;
		case 1: Chapter_10_Assignment2(); break;
		case 2: Chapter_10_Assignment3(); break;
		case 3: Chapter_10_Assignment4(); break;
		case 4: Chapter_10_Assignment5(); break;
		case 5: Chapter_10_Assignment6(); break;
		case 6: Chapter_10_Assignment7(); break;
		case 7: Chapter_10_Assignment8(); break;
		case 8: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != amountofoptions - 1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 26.08.2017
//Created by: Marcin Nowak