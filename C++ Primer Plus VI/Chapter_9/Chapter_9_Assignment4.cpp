#include "../stdafx.h"
#include "Chapter_9_Functions.h"
#include "Sales.h"

/*
Napisz trzyplikowy program bazuj¹cy na poni¿szej przestrzeni nazw:
namespace SALES
{
 const int QUARTERS =4
 struct Sales
 {
  double sales[QUARTERS];
  double average;
  double max;
  double min;
 }

 //kopiuje najmniejszy z czterech lub n elementów tablicy ar
 //do sk³adowej sales struktury s i oblicza oraz zachowuje w odpowiednich
 //sk³adowych struktury sales wartoœci, œredni¹, minimaln¹ i maksymaln¹;
 //zeruje pozosta³e elementy tablicy sales (jeœli s¹);
 void setSales(Sales &s, const double ar[], int n);

 //pobiera interaktywnie informacje dla 4 kwarta³ów,
 //zachowuje je w sk³adowej sales struktury s i oblicza oraz zachowuje
 //w odpowiednich sk³adowych s wartoœæ œredni¹, minimaln¹ i maksymaln¹
 void setSales(Sales & s);
 
 //wyœwietla komplet informacji ze struktury s
 void showSales(const Sales & s);
}

Pierwszy z plików powinien byæ plikiem nag³ówkowym deklaruj¹cym powy¿sz¹ przestrzeñ nazw.
Drugi plik powinien zawieraæ kod Ÿród³owy uzupe³niaj¹cy przestrzeñ nazw z pliku nag³ówkowego
o definicje zadeklarowanych w niej funkcji. Wreszcie trzeci plik powinien deklarowaæ dwa
obiekty typu Sales. Jeden z nich powienien wype³niæ interaktywn¹ wersjê funkcji setSales(),
drugi jej wersjê nieinteraktywn¹. Na koniec pownien wyœwietliæ zawartoœæ obu struktur
wywo³aniem showSales().
*/

int Chapter_9_Assignment4()
{
	double arr[SALES::QUARTERS] = { 4000, 57632, 7.89, 875.4 };
	SALES::Sales year1;
	SALES::Sales year2;
	SALES::setSales(year1, arr, SALES::QUARTERS);
	SALES::setSales(year2);
	SALES::showSales(year1);
	SALES::showSales(year2);
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return 0;
}

//date of creation: 18.08.2017
//Created by: Marcin Nowak