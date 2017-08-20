#include "../stdafx.h"
#include "Chapter_7_Functions.h"

const int arsize = 10;

double* Fill_array(double*, int);
void Show_array(double*, int);
void Reverse_array(double*, int);

int Chapter_7_Assignment6()
{
	std::cout << "Assignment 6 :\n" << std::endl;
	double testarray[arsize]{};
	int true_size = 0;
	true_size = (int)((Fill_array(testarray, arsize)) - testarray);
	std::cout << "Number of filled elements of array: " << true_size << "\n";
	Show_array(testarray, true_size-1);
	std::cout << "Reversed, array looks looks like this:\n";
	Reverse_array(testarray, true_size-1);
	Show_array(testarray, true_size-1);
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}

double* Fill_array(double* arrname, int size)
{
	std::cout << "\nInput number: ";
	while (std::cin >> *(arrname++))
	{
		size--;
		if (size <= 1) return arrname;
		std::cout << "Input number: ";
	};
	return arrname-1;
};

void Show_array(double* arrname, int size)
{
	double iterator = 0;
	do
	{
		std::cout << "Element " << iterator << " : " << *(arrname++) << std::endl;
		iterator++;
	} while (1<=size--);
	return;
};

void Reverse_array(double* arrname, int size)
{
	int iterator = 0;
	double helper = 0;
	do
	{
		helper = *(arrname + (size));
		*(arrname + (size)) = *(arrname + iterator);
		*(arrname + iterator) = helper;
		iterator++; size--;
		0;
	} while ( iterator< size);
	return;
};

//date of creation: 28.07.2017
//Created by: Marcin Nowak