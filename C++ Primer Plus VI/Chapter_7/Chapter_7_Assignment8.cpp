#include "../stdafx.h"
#include "Chapter_7_Functions.h"

const int arsize = 4;
const char* seasons[arsize]{ "spring", "summer","autumn","winter" };
struct monthly
{
	double expenses;
};

//listing 7.15 - bez array, 2 wersje:
//-const char* pory roku, double wydatki[]
//-const char* pory roku, struct x double wydatki[]

void fillv1(double* expenses);
void showv1(double* expenses);

void Version1()
{
	double expenses[arsize]{};
	fillv1(expenses);
	showv1(expenses);
	return;
};

void fillv2(monthly* monthly);
void showv2(monthly* monthly);


void Version2()
{
	monthly costs[arsize];
	fillv2(costs);
	showv2(costs);
	return;
}


int Chapter_7_Assignment8()
{
	
	std::cout << "Assignment 8 :\n" << std::endl;
	//Version1();
	Version2();
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}

void fillv1(double* expenses)
{
	for (int i = 0; i < arsize; i++)
	{
		std::cout << "\nInput expenses in " << seasons[i] << " season :";
		std::cin >> *(expenses+i);
	};
	return;
};

void showv1(double* expenses)
{
	for (int i = 0; i < arsize; i++)
	{
		std::cout << "\n" << seasons[i] << " expenses: " << *(expenses+i);
	};
	return;
};

void fillv2(monthly* monthly)
{
	for (int i = 0; i < arsize; i++)
	{
		std::cout << "\nInput expenses for " << seasons[i] << " season:";
		std::cin >> (monthly+i) -> expenses;
	}
	return;
};

void showv2(monthly* monthly)
{
	for (int i = 0; i < arsize; i++)
	{
		std::cout << "\n" << seasons[i] << " expenses: " << (monthly + i)->expenses;
	}
	return;
};

//date of creation: 28.07.2017
//Created by: Marcin Nowak