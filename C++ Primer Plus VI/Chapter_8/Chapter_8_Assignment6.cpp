#include "../stdafx.h"
#include "Chapter_8_Functions.h"
#include <cctype>

const int doublearsize = 4;
const int intarsize = 5;

template<typename T, typename T2>
T maxn(T* tab, T2 numofelements);

int Chapter_8_Assignment6()
{
	int Tab1[intarsize] = { 1, 6, 7, 9, 4 };
	double Tab2[doublearsize] = { 1.67, 5.89, 90.543, 28.65 };
	char* Tab3[intarsize] = { "some", "random", "words", "just to", "fill the tab" };
	std::cout << "\nBiggest element of Tab1= " << maxn(Tab1, intarsize);
	std::cout << "\nBiggest element of Tab1= " << maxn(Tab2, doublearsize);
	std::cout << "\nLongest element of Tab3 is located in adress= " << maxn(Tab3, intarsize);
	std::cout << "\nPress any key to exit ..." << std::endl;
	_getch();
	return 0;
}

template<typename T, typename T2>
T maxn(T* tab, T2 numofelements)
{
	T max=0;
	for (int i = 0; i < numofelements; i++)
	{
		if (max < tab[i]) { max = tab[i]; };
	};
	return max;
};

template<typename T, typename T2>
T maxn(char** tab, T2 numofelements)
{
	char* longestelement;
	*longestelement = ' ';
	for (int i = 0; i < numofelements; i++)
	{
		if (strlen(longestelement) < strlen(tab[i])) { longestelement = tab[i] };
	};
	return longestelement;
};

//date of creation: 05.08.2017
//Created by: Marcin Nowak