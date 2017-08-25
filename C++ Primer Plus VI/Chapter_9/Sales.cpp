#include "../stdafx.h"
#include "Sales.h"
#include <float.h>

//kopiuje najmniejszy z czterech lub n element�w tablicy ar
//do sk�adowej sales struktury s i oblicza oraz zachowuje w odpowiednich
//sk�adowych struktury sales warto�ci, �redni�, minimaln� i maksymaln�;
//zeruje pozosta�e elementy tablicy sales (je�li s�);

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

//pobiera interaktywnie informacje dla 4 kwarta��w,
//zachowuje je w sk�adowej sales struktury s i oblicza oraz zachowuje
//w odpowiednich sk�adowych s warto�� �redni�, minimaln� i maksymaln�
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

//wy�wietla komplet informacji ze struktury s
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