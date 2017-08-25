#include "../stdafx.h"
#include "Sales.h"
#include <float.h>

//kopiuje najmniejszy z czterech lub n element�w tablicy ar
//do sk�adowej sales struktury s i oblicza oraz zachowuje w odpowiednich
//sk�adowych struktury sales warto�ci, �redni�, minimaln� i maksymaln�;
//zeruje pozosta�e elementy tablicy sales (je�li s�);
void SALES::setSales(Sales &s, const double ar[], int n)
{
	double min = DBL_MAX;
	double max = DBL_MIN;
	double average = 0;
	for (auto i = 0; i < n; i++) 
	{
		while (ar[i] < min)	min = ar[i];
		while (ar[i] > max) max = ar[i];
		average += ar[i];
	};
	//if it IS NOT a translation error THIS 
	s.sales[0] = min;
	for (auto i = 1; i <n; i++)
	{
		s.sales[i] = 0;
	};
	//if it IS translation error THIS
	/*
	for (auto i = 0; i <n; i++)
	{
		s.sales[i] = ar[i];
	};
	*/
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