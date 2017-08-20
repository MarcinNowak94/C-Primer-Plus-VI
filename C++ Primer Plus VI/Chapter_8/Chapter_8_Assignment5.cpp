#include "../stdafx.h"
#include "Chapter_8_Functions.h"

const int arsize = 5;

template<class Temp>
Temp max5(Temp* arr)
{
	Temp max = 0;
	for (int i = 0; i < arsize; i++)
	{
		if (max < arr[i]) { max = arr[i];}
	}
	return max;
};

int Chapter_8_Assignment5()
{
	int Tab1[arsize] = {1, 6, 7, 9, 4};
	double Tab2[arsize] = { 1.67, 5.89, 90.543, 28.65, 38.6 };
	std::cout << "Max value of TAB1 is: " << max5(Tab1);
	std::cout << "\nMax value of TAB2 is: " << max5(Tab2);
	std::cout << "\nPress any key to exit ..." << std::endl;
	_getch();
	return 0;
}

//date of creation: 05.08.2017
//Created by: Marcin Nowak