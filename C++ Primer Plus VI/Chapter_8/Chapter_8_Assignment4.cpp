#include "../stdafx.h"
#include "Chapter_8_Functions.h"
#include <cstring>

struct stringy
{
	char * str;
	int ct;
};

void set(stringy& strngy, char* givenphrase);
void show(stringy& strngy, int amount=1);
void show(char * givenphrase, int times=1);


int Chapter_8_Assignment4()
{
	stringy beany;
	char testing[] = "reality is not the same as in the old days.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	std::cout << "Press any key to exit ..." << std::endl;
	_getch();
	return 0;
}

void set(stringy& strngy, char* givenphrase)
{
	char* newpointer;
	newpointer = new char[std::strlen(givenphrase)];
	strcpy(newpointer, givenphrase);
	strngy.str = newpointer;
	strngy.ct = std::strlen(newpointer);
	return;
};

void show(stringy& strngy, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		std::cout << strngy.str << std::endl;
	};
	return;
};

void show(char * givenphrase, int times)
{
	for (int i = 0; i < times; i++)
	{
		std::cout << givenphrase << std::endl;
	};
	return;
};

//date of creation: 05.08.2017
//Created by: Marcin Nowak