#include "../stdafx.h"
#include "Chapter_8_Functions.h"

//listing 8.14 - 2 templates SumArray() returning sum of arr elements not showing values, program should output amount of items and sum of debt

/*
Zmodyfikuj program z listingu 8.14 tak aby stosowa³ dwa szablony funkcji o nazwie SumArray(), zwracaj¹cej sumê elementów tablicy, a nie wypisuj¹cej zawartoœci tej tablicy.
Program powinien podawaæ te¿ ³¹czn¹liczbê przedmiotów i sumê zad³u¿enia.
*/

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
double SumArray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int Chapter_8_Assignment7()
{
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3]
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3];
	for (int i = 0; i < 3; i++) pd[i] = &mr_E[i].amount;
	std::cout << "Sum of Mr.E. items:";
	std::cout << SumArray(things, 6);
	std::cout << "\nShowing Mr.E. debts:";
	std::cout << SumArray(pd, 3);
	// **********************************************************************************************************************************
	std::cout << "\nPress any key to exit ..." << std::endl;
	_getch();
	return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
	//std::cout << "Template A:\n";
	int sum = 0;
	for (int i = 0; i < n; i++)	sum+=arr[i];
	return sum;
};

template <typename T>
double SumArray(T * arr[], int n)
{
	//std::cout << "Template B:\n";
	double sum = 0;
	for (int i = 0; i < n; i++)	sum+=*arr[i] ;
	return sum;
};

//date of creation: 05.08.2017
//Created by: Marcin Nowak