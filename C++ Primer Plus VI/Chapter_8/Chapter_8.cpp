// Rozdzia³ 8.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "Chapter_8_Functions.h"
#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"

int Chapter_8_Assignment1();
int Chapter_8_Assignment2();
int Chapter_8_Assignment3();
int Chapter_8_Assignment4();
int Chapter_8_Assignment5();
int Chapter_8_Assignment6();
int Chapter_8_Assignment7();

int Chapter_8()
{
	std::string options[]
	{ 
		"Assignment 1:\tFunction overloading: display string",
		"Assignment 2:\tCandybar",
		"Assignment 3:\tUppercase a string",
		"Assignment 4:\tTampering with string structure",
		"Assignment 5:\tTemplate arrays max values",
		"Assignment 6:\tTemplate tab functions specialization",
		"Assignment 7:\tListing 8.16 templating"
	};
	int input;
	do
	{
		input = simplemenu(options, "Chapter 8");
		switch (input)
		{
		case 0: Chapter_8_Assignment1(); break;
		case 1: Chapter_8_Assignment2(); break;
		case 2: Chapter_8_Assignment3(); break;
		case 3: Chapter_8_Assignment4(); break;
		case 4:	Chapter_8_Assignment5(); break;
		case 5: Chapter_8_Assignment6(); break;
		case 6: Chapter_8_Assignment7(); break;			//TODO
		case 7: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != (sizeof(options) / sizeof(options[0]))-1 && input != 27);
	return input;	//used only in case of pressing ESC
}

//date of creation: 05.08.2017
//Created by: Marcin Nowak