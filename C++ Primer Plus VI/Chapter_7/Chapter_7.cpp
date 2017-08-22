// Rozdzia³ 7.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "Chapter_7_Functions.h"
#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"

//problem to solve for later
int Chapter_7_Assignment1();
int Chapter_7_Assignment2();
int Chapter_7_Assignment3();
int Chapter_7_Assignment4();
int Chapter_7_Assignment5();
int Chapter_7_Assignment6();
int Chapter_7_Assignment7();
int Chapter_7_Assignment8();
int Chapter_7_Assignment9();
int Chapter_7_Assignment10();

int Chapter_7()
{
	std::string options[]
	{ 
		"Assignment 1:\tHarmonic mean",
		"Assignment 2:\tAverage scores",
		"Assignment 3:\tBanana displayer",
		"Assignment 4:\tLottery winning chance",
		"Assignment 5:\tFactorial recursively",
		"Assignment 6:\tArray displayer",
		"Assignment 7:\tProperty reevaluator",
		"Assignment 8:\tListing 7.17 without array",
		"Assignment 9:\tGroup of students",
		"Assignment 10:\tFunction pointers",
		"Back"
	};
	const int amountofoptions = 11;
	int input;
	do
	{
		input = simplemenu(options, amountofoptions);
		switch (input)
		{
		
		case 0: Chapter_7_Assignment1(); break;
		case 1: Chapter_7_Assignment2(); break;
		case 2: Chapter_7_Assignment3(); break;
		case 3: Chapter_7_Assignment4(); break;
		case 4:	Chapter_7_Assignment5(); break;
		case 5: Chapter_7_Assignment6(); break;
		case 6: Chapter_7_Assignment7(); break;
		case 7: Chapter_7_Assignment8(); break;
		case 8: Chapter_7_Assignment9(); break;
		case 9: Chapter_7_Assignment10(); break;
		
		case 10: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != amountofoptions - 1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 28.07.2017
//Created by: Marcin Nowak