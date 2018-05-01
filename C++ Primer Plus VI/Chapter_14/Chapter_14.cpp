#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"
#include "Chapter_14_Functions.h" 


int Chapter_14()
{
	std::string options[]
	{
		"Assignment 1:\t",
		"Assignment 2:\t",
		"Assignment 3:\t",
		"Assignment 4:\t",
		"Assignment 5:\t"
	};
	int input;
	do
	{
		input = simplemenu(options, "Chapter 14");
		switch (input)
		{
		case 0: Chapter_14_Assignment1(); break;
		case 1: Chapter_14_Assignment2(); break;
		case 2: Chapter_14_Assignment3(); break;
		case 3: Chapter_14_Assignment4(); break;
		case 4: Chapter_14_Assignment5(); break;
		case 5: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != (sizeof(options) / sizeof(options[0])) - 1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 29.04.2017
//Created by: Marcin Nowak