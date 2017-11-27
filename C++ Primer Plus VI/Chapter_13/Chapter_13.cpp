#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"
#include "Chapter_13_Functions.h" 


int Chapter_13()
{
	std::string options[]
	{
		"Assignment 1:\t",
		"Assignment 2:\t",
		"Assignment 3:\t",
		"Assignment 4:\t"
	};
	int input;
	do
	{
		input = simplemenu(options, "Chapter 13");
		switch (input)
		{
		case 0: Chapter_13_Assignment1(); break;
		case 1: Chapter_13_Assignment2(); break;
		case 2: Chapter_13_Assignment3(); break;
		case 3: Chapter_13_Assignment4(); break;
		case 4: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != (sizeof(options) / sizeof(options[0])) - 1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 26.11.2017
//Created by: Marcin Nowak