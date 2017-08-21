#include "../stdafx.h"
#include "Chapter_9_Functions.h"

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

 //kopije najmniejszy z czterech lub n elementów tablicy ar
 //do sk³adowej sales struktury s i oblicza oraz zachowuje w odpowiednich
 //sk³adowych struktury sales wartoœci, œredni¹, minimaln¹ i maksymaln¹;
 //zeruje pozosta³e elementy tablicy sales (jeœli s¹);
 void setSales(Sales &s, const double ar[], int n);

 //pobiera interaktywnie informacje dla 4 kwarta³ów,
 //zachowuje je w sk³adowej sales struktury s i oblicza oraz zachowuje
 //w odpowiednich sk³adowych s wartoœæ œredni¹, minimaln¹ i maksymaln¹
 void serSales(Sales & s);
 
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
	//TODO
	std::cout << "\aNothing to see here (YET), move along.\n" << std::endl;
	_getch();
	return 0;
}

//date of creation: 18.08.2017
//Created by: Marcin Nowak