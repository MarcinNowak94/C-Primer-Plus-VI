#include "../stdafx.h"
#include "Chapter_9_Functions.h"

/*
Napisz trzyplikowy program bazuj�cy na poni�szej przestrzeni nazw:
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

 //kopije najmniejszy z czterech lub n element�w tablicy ar
 //do sk�adowej sales struktury s i oblicza oraz zachowuje w odpowiednich
 //sk�adowych struktury sales warto�ci, �redni�, minimaln� i maksymaln�;
 //zeruje pozosta�e elementy tablicy sales (je�li s�);
 void setSales(Sales &s, const double ar[], int n);

 //pobiera interaktywnie informacje dla 4 kwarta��w,
 //zachowuje je w sk�adowej sales struktury s i oblicza oraz zachowuje
 //w odpowiednich sk�adowych s warto�� �redni�, minimaln� i maksymaln�
 void serSales(Sales & s);
 
 //wy�wietla komplet informacji ze struktury s
 void showSales(const Sales & s);
}

Pierwszy z plik�w powinien by� plikiem nag��wkowym deklaruj�cym powy�sz� przestrze� nazw.
Drugi plik powinien zawiera� kod �r�d�owy uzupe�niaj�cy przestrze� nazw z pliku nag��wkowego
o definicje zadeklarowanych w niej funkcji. Wreszcie trzeci plik powinien deklarowa� dwa
obiekty typu Sales. Jeden z nich powienien wype�ni� interaktywn� wersj� funkcji setSales(),
drugi jej wersj� nieinteraktywn�. Na koniec pownien wy�wietli� zawarto�� obu struktur
wywo�aniem showSales().
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