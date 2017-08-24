#include "../stdafx.h"
#include "Chapter_9_Functions.h"

/*
Przepisz kod z listingu 9.9 zastêpuj¹c w nim tablicê znaków obiektem klasy string. Program
w nowej wersji nie powinien musieæ sprawdzaæ, czu wprowadzany na wejœcie ci¹g mieœci siê 
w buforze, i wykrywaæ pusty wiersz poprzez porównanie obiektu bufora z litera³em ""
*/

//Listing 9.9
/*
// static.cpp -- stosowanie lokalnej zmiennej statycznej
#include <iostream>
// sta³e:
const int ArSize = 10;

// prototyp funkcji:
void strcount(const char * str);

int main()
{
using namespace std;
char input[ArSize];
char next;

cout << "WprowadŸ wiersz:\n";
cin.get(input, ArSize);
while (cin)
{
cin.get(next);
while (next != '\n')       // wiersz nie zmieœci³ siê w buforze!
cin.get(next); // porzucenie reszty znaków z wejœcia
strcount(input);
cout << "WprowadŸ nastêpny wiersz (wiersz pusty koñczy wprowadzanie):\n";
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
while (*str++)                  // przejdŸ na koniec ci¹gu
count++;
total += count;
cout << count << " znaków\n";
cout << "£¹cznie "<< total << " znaków\n";
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