#include "../stdafx.h"
#include "Chapter_7_Functions.h"

const int arsize = 5;

//listing 7.7
//funkcje maj¹ otrzymywaæ adres pocz¹tkoy i koñcowy
//fill array - zwraca ostatni element tablicy+1
//inne funkcje maj¹ u¿ywaæ fill array jako drugiego elementu

double* Fill_array(double*, double*);
void Show_array(double*, double*);
void Revalue(double factor, double*, double*);

int Chapter_7_Assignment7()
{
	std::cout << "Assignment 7 :\n" << std::endl;
	double properties[arsize];
	double* lastelem = Fill_array(properties, properties + arsize);
	Show_array(properties, lastelem);
	double valuefactor = 0;
	if (0<lastelem-properties)
	{
		std::cout << "\nInput value change factor: ";
		while (!(std::cin >> valuefactor))
		{
			std::cin.clear(); std::cin.ignore(1000, '\n');
			std::cout << "\nError! Input real number: ";
		};
	};
	Revalue(valuefactor, properties, lastelem);
	Show_array(properties, lastelem);
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}

double* Fill_array(double* firstelement, double* lastelement)
{
	char temp = ' ';
	std::cout << "Input value of property in adress " << firstelement << " :";
		while (std::cin >> *firstelement && firstelement<(lastelement-1))
		{
			firstelement++;
			std::cout << "Input value of property in adress " << firstelement << " :";
		};
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	return lastelement; 
};

void Show_array(double* firstelement, double* lastelement)
{
	while (firstelement < lastelement-1)
	{
		std::cout << "\nProperty : " << *(firstelement);
		firstelement++;
	};
	return;  
};

void Revalue(double factor, double* firstelement, double* lastelement)
{
	while (firstelement < lastelement-1)
	{
		(*firstelement) *= factor;
		firstelement++;
	};
	std::cout << "\nProperties reevaluated by given factor!";
	return; 
};

//date of creation: 28.07.2017
//Created by: Marcin Nowak