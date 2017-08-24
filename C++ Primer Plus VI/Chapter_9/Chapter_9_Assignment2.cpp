#include "../stdafx.h"
#include "Chapter_9_Functions.h"

/*
Przepisz kod z listingu 9.9 zast�puj�c w nim tablic� znak�w obiektem klasy string. Program
w nowej wersji nie powinien musie� sprawdza�, czu wprowadzany na wej�cie ci�g mie�ci si� 
w buforze, i wykrywa� pusty wiersz poprzez por�wnanie obiektu bufora z litera�em ""
*/

//Listing 9.9
/*
// static.cpp -- stosowanie lokalnej zmiennej statycznej
#include <iostream>
// sta�e:
const int ArSize = 10;

// prototyp funkcji:
void strcount(const char * str);

int main()
{
using namespace std;
char input[ArSize];
char next;

cout << "Wprowad� wiersz:\n";
cin.get(input, ArSize);
while (cin)
{
cin.get(next);
while (next != '\n')       // wiersz nie zmie�ci� si� w buforze!
cin.get(next); // porzucenie reszty znak�w z wej�cia
strcount(input);
cout << "Wprowad� nast�pny wiersz (wiersz pusty ko�czy wprowadzanie):\n";
cin.get(input, ArSize);
}
cout << "Koniec\n";
return 0;
}

void strcount(const char * str)
{
using namespace std;
static int total = 0;          // statyczna zmienna lokalna
int count = 0;                 // automatyczna zmienna lokalna

cout << "\"" << str << "\" zawiera ";
while (*str++)                  // przejd� na koniec ci�gu
count++;
total += count;
cout << count << " znak�w\n";
cout << "��cznie "<< total << " znak�w\n";
}
*/

void strcount(const std::string* sentence);

int Chapter_9_Assignment2()
{
	std::string input;
	do
	{
		std::cout << "Input empty string to exit or input line of text:\n";
		std::getline(std::cin, input, '\n');
		strcount(&input);
	} while (0 != input.length());
	std::cout << "Back to menu then.\n"
		<< "Press any key to continue..."
		<< std::endl;
	_getch();
	return 0;
}

void strcount(const std::string* sentence)
{
	while (0 == (*sentence).length()) { std::cout << "Line of input is empty!\n"; return;};
	std::cout << "Input line of text \\" << *sentence << "\\ is " << (*sentence).length() << " characters long.\n";
};
//date of creation: 18.08.2017
//Created by: Marcin Nowak