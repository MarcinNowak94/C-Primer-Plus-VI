#include "Chapter_11_Functions.h" 
#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"


int Chapter_11_Assignment1(); //TODO: Chapter_11_Assignment1
int Chapter_11_Assignment2(); //TODO: Chapter_11_Assignment2	
int Chapter_11_Assignment3(); //TODO: Chapter_11_Assignment3
int Chapter_11_Assignment4(); //TODO: Chapter_11_Assignment4
int Chapter_11_Assignment5(); //TODO: Chapter_11_Assignment5
int Chapter_11_Assignment6(); //TODO: Chapter_11_Assignment6
int Chapter_11_Assignment7(); //TODO: Chapter_11_Assignment7


int Chapter_11()
{
	std::string options[]
	{
		"Assignment 1:\tWalker into a file.",
		"Assignment 2:\tModified listings 11.13 and 11.14",
		"Assignment 3:\tWalker statistics for n trials",
		"Assignment 4:\tTime class example using friend functions",
		"Assignment 5:\tChanging Stonewt class",
		"Assignment 6:\tStonewt class. Rewriting relational operators",
		"Assignment 7:\tComplex class dealing with complex numbers"
	};
	int input;
	do
	{
		input = simplemenu(options, "Chapter 11");
		switch (input)
		{
		case 0: Chapter_11_Assignment1(); break;
		case 1: Chapter_11_Assignment2(); break;
		case 2: Chapter_11_Assignment3(); break;
		case 3: Chapter_11_Assignment4(); break;
		case 4: Chapter_11_Assignment5(); break;
		case 5: Chapter_11_Assignment6(); break;
		case 6: Chapter_11_Assignment7(); break;
		case 7: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != (sizeof(options) / sizeof(options[0]))-1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 30.08.2017
//Created by: Marcin Nowak