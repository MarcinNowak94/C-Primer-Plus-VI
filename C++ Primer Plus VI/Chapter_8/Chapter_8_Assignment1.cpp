#include "../stdafx.h"
#include "Chapter_8_Functions.h"

void displaycharstring(char * charstring);
void displaycharstring(char * charstring, int times);

int Chapter_8_Assignment1()
{
	char chrstrng[] = "janusz";
	displaycharstring(chrstrng);
	std::cout << "\nNow with additional parameter\n";
	displaycharstring(chrstrng, 4);
	std::cout << "Press any key to exit ..." << std::endl;
	_getch();
	return 0;
}

void displaycharstring(char * charstring)
{
	std::cout << "\t\tGiven string\n" << charstring << std::endl;
	return;
};

void displaycharstring(char * charstring, int times)
{
	for (int i = 0; i < times; i++)
	{
		std::cout << "\n" << i+1 << ": " << charstring << "\n";
	}
	return;
};

//date of creation: 05.08.2017
//Created by: Marcin Nowak