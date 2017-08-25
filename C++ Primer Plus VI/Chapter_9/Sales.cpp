#include "../stdafx.h"
#include "Sales.h"
#include <float.h>

//kopiuje najmniejszy z czterech lub n elementów tablicy ar
//do sk³adowej sales struktury s i oblicza oraz zachowuje w odpowiednich
//sk³adowych struktury sales wartoœci, œredni¹, minimaln¹ i maksymaln¹;
//zeruje pozosta³e elementy tablicy sales (jeœli s¹);

//ORIGINAL:
// copies the lesser of 4 or n items from the array ar 
// to the sales member of s and computes and stores the 
// average, maximum, and minimum values of the entered items; 
// remaining elements of sales, if any, set to 0

void SALES::setSales(Sales &s, const double ar[], int n)
{
	double min = DBL_MAX;
	double max = DBL_MIN;
	int minindex = 0;
	double average = 0;
	for (auto i = 0; i < n; i++) 
	{
		while (ar[i] < min) { min = ar[i]; minindex = i; };
		while (ar[i] > max) max = ar[i];
		average += ar[i];
	};
	for (auto i = 1; i <n; i++)
	{
		if (i == minindex) { s.sales[i] = min; }
		else { s.sales[i] = 0; };
	};
	s.min = min;
	s.max = max;
	s.average = average / n;
	return;
};

//pobiera interaktywnie informacje dla 4 kwarta³ów,
//zachowuje je w sk³adowej sales struktury s i oblicza oraz zachowuje
//w odpowiednich sk³adowych s wartoœæ œredni¹, minimaln¹ i maksymaln¹
void SALES::setSales(Sales & s) 
{
	s.max = DBL_MIN;
	s.min = DBL_MAX;
	double average = 0;
	std::cout << "(" << &s << ")\n"
		<<"\nInput amount of sales in each quarter:";
	for (auto i = 0; i < QUARTERS; i++)
	{
		std::cout << "\nQuarter " << i << ":";
		std::cin >> s.sales[i];
		while (s.sales[i] < s.min)	s.min = s.sales[i];
		while (s.sales[i] > s.max)	s.max = s.sales[i];
		average += s.sales[i];
	};
	s.average = average / QUARTERS;
	return;
};

//wyœwietla komplet informacji ze struktury s
void SALES::showSales(const SALES::Sales & s)
{
	std::cout << "\n(" << &s << ")Sales summary:";
	for (auto i = 0; i < QUARTERS; i++)
	{
		std::cout << "\nQuarter " << i << ":\t" << s.sales[i];
	};
	std::cout << "\nMinimum:\t" << s.min
		<< "\nMaximum:\t" << s.max
		<< "\nAverage:\t" << s.average << std::endl;
	return;
};