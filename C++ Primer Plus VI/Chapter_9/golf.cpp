#include "../stdafx.h"
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
	//wersja nieinteraktywna
	//funkcja ustawia w strukturze golf zadane nazwisko i handicap
	//na podstawie argumentów wywo³ania
	for (int i = 0; i < Len || name[i]!='\0'; i++)
	{
		g.fullname[i] = name[i];
	}
	handicap(g, hc);
	return;
};

void setgolf(golf & g)
{
	//wersja interaktywna
	// Funkcja pobiera nazwisko i wartoœæ handicapu od u¿ytkownika
	// i ustawia pola struktury g zgodnie z pobranymi wartoœciami;
	// zwraca 1, jeœli uda³o siê odczytaæ z wejœcia wartoœæ pola name, 
	//albo 0, kiedy pole name jest ci¹giem pustym
	//extern const int Len;
	g.fullname[0] = '\0';
	int iterator = 0;
	char helper;
	std::cin.clear(); std::cin.ignore(1000, '\n');
	std::cout << "\nInput golf players:\n"
		<< "name: \t";
	helper = std::cin.get();
	 while (helper!='\n')
	 {
		g.fullname[iterator] = helper;
	    helper = std::cin.get();
		iterator++;
	 };
	 g.fullname[iterator] = '\0';
	//if ('\0'==g.fullname) throw 0;    
	//possible solution for returning 0/1 problem
	//2nd possible solution - extern bool variable
	//this function is declared as 'void' adhearing to given specification - it cannot return value (exception handling wasn't covered yet).
	std::cin.clear(); std::cin.ignore(1000,'\n');
	std::cout << "handicap: \t";
	std::cin >> g.handicap;
	return;
};			

void handicap(golf & g, int hc)
{
	g.handicap = hc;
	return;
};

void showgolf(const golf & g)
{
	std::cout << "\nShowing golf player:"
		<< "\nname:\t\t" << g.fullname
		<< "\nhandicap:\t" << g.handicap << std::endl;
	return;
};