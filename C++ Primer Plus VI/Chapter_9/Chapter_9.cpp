// Rozdzia³ 8.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "../Rozdzia³ 9/Chapter_9_Functions.h"
#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"

int Chapter_9_Assignment1();
int Chapter_9_Assignment2();
int Chapter_9_Assignment3();
int Chapter_9_Assignment4();

int Chapter_9()
{
	std::string options[]
	{ 
		"Assignment 1:\t",
		"Assignment 2:\t",
		"Assignment 3:\t",
		"Assignment 4:\t",
		"Back"
	};
	const int amountofoptions = 5;
	int input;
	do
	{
		input = simplemenu(options, amountofoptions);
		switch (input)
		{
		case 0: Chapter_9_Assignment1(); break;		//TODO
		case 1: Chapter_9_Assignment2(); break;		//TODO
		case 2: Chapter_9_Assignment3(); break;		//TODO
		case 3: Chapter_9_Assignment4(); break;		//TODO
		case 4: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != amountofoptions - 1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 18.08.2017
//Created by: Marcin Nowak