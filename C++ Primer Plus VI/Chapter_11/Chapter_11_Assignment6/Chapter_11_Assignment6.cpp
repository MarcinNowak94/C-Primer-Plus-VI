#include "../../stdafx.h"
#include "../Chapter_11_Functions.h"
#include "stonewt_2.h"

int Chapter_11_Assignment6()
{
	Stonewt_2::Stonewt weightarr[]
	{
		{ (int)random(), (double)random() },
		{(int)random(), (double)random() },
		{11},
		{},
		{},
		{},
	};
	Stonewt_2::Stonewt heavy_one(11, 0);
	Stonewt_2::Stonewt smallest(DBL_MAX);
	Stonewt_2::Stonewt largest(DBL_MIN);

	for (size_t i = 3; i < sizeof(weightarr)/sizeof(weightarr[0]); i++)
	{
		weightarr[i] = Stonewt_2::Stonewt((int)random(), (double)random());
	};
	int eleven_or_more = 0;
	for (size_t i = 0; i < sizeof(weightarr)/sizeof(weightarr[0]); i++)
	{
		std::cout << "\n#" << i << ": ";
		weightarr[i].show_stn();
		if (weightarr[i] < smallest) smallest = weightarr[i];
		if (weightarr[i] > largest) largest = weightarr[i];
		if (weightarr[i] >= heavy_one) eleven_or_more++;
	};
	std::cout << "\nSmallest:\t"; smallest.show_stn();
	std::cout << "\nLargest:\t"; largest.show_stn();
	std::cout << "\nThere were " << eleven_or_more << " equal or greater than 11stones.\n";
	_getch();
	return 0;
};

/*
6. Rewrite the Stonewt class (Listings 11.16 and 11.17) so that it overloads all six
relational operators.The operators should compare the pounds members and return
a type bool value.Write a program that declares an array of six Stonewt objects and
initializes the first three objects in the array declaration.Then it should use a loop
to read in values used to set the remaining three array elements.Then it should
report the smallest element,the largest element,and how many elements are greater
or equal to 11 stone.(The simplest approach is to create a Stonewt object initialized
to 11 stone and to compare the other objects with that object.)
*/