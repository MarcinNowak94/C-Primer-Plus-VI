#include "../stdafx.h"
#include "Chapter_7_Functions.h"

struct box
{
	char producent[40];
	float height;
	float width;
	float length;
	float volume;
};

void DisplayByValue(box);
void DisplayByAdress(box*);

int Chapter_7_Assignment3()
{
	box bananabox = { "Chiquita!", 10, 10, 30, (float)0.87 };
	std::cout << "Assignment 3 :\n" << std::endl;
	DisplayByValue(bananabox);
	DisplayByAdress(&bananabox);
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}

void DisplayByValue(box givenbox)
{
	std::cout << "\nGiven box parameters:"
		<< "\nProducent:\t" << givenbox.producent
		<< "\nHeight:\t\t" << givenbox.height
		<< "\nWidth:\t\t" << givenbox.width
		<< "\nLenght:\t\t" << givenbox.length
		<< "\nVolume:\t\t" << givenbox.volume << std::endl;
	return;
};

void DisplayByAdress(box* boxpntr)
{
	std::cout << "\nGiven box(" << boxpntr << ") parameters:"
		<< "\nProducent:\t" << (*boxpntr).producent			//method1
		<< "\nHeight:\t\t" << boxpntr->height				//method2
		<< "\nWidth:\t\t" << (*boxpntr).width
		<< "\nLenght:\t\t" << (*boxpntr).length;
	(*boxpntr).volume = (*boxpntr).height * (*boxpntr).width * (*boxpntr).length;
		std::cout << "\nVolume:\t\t" << (*boxpntr).volume << std::endl;
	return;
};

//date of creation: 28.07.2017
//Created by: Marcin Nowak