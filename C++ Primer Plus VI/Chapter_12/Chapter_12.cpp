#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"
#include "Chapter_12_Functions.h" 

/*
int Chapter_12_Assignment1(); //TODO: Chapter_12_Assignment1
int Chapter_12_Assignment2(); //TODO: Chapter_12_Assignment2
int Chapter_12_Assignment3(); //TODO: Chapter_12_Assignment3
int Chapter_12_Assignment4(); //TODO: Chapter_12_Assignment4
int Chapter_12_Assignment5(); //TODO: Chapter_12_Assignment5
int Chapter_12_Assignment6(); //TODO: Chapter_12_Assignment6
*/
int Chapter_12()
{
	std::string options[]
	{
		"Assignment 1:\t'Cow' class.",
		"Assignment 2:\tImproving 'String'",
		"Assignment 3:\tDynamically allocated 'Stack' class",
		"Assignment 4:\t'Stack' class redefined",
		"Assignment 5:\t100 hours at ATM",
		"Assignment 6:\t100 hours and 2 ATMs"
	};
	int input;
	do
	{
		input = simplemenu(options, "Chapter 12");
		switch (input)
		{
		case 0: Chapter_12_Assignment1(); break;
		case 1: Chapter_12_Assignment2(); break;
		case 2: Chapter_12_Assignment3(); break;
		case 3: Chapter_12_Assignment4(); break;
		case 4: Chapter_12_Assignment5(); break;
		case 5: Chapter_12_Assignment6(); break;
		case 6: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != (sizeof(options) / sizeof(options[0]))-1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 30.08.2017
//Created by: Marcin Nowak