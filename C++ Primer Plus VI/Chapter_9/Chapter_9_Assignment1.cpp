#include "../stdafx.h"
#include "Chapter_9_Functions.h"
#include "golf.h"

/*
Dany jest plik nag³ówkowy:
golf.h -- do pe9-1.cpp

const int Len=40;
struct golf
{
 char fullname[Len];
 int handicap;
};

//wersja nieinteraktywna
//funkcja ustawia w strukturze golf zadane nazwisko i handicap
//na podstawie argumentów wywo³ania
void setgolf(golf & g, const char * name, int hc);

//wersja interaktywna
// Funkcja pobiera nazwisko i wartoœæ handicapu od u¿ytkownika
// i ustawia pola struktury g zgodnie z pobranymi wartoœciami;
// zwraca 1, jeœli uda³o siê odczytaæ z wejœcia wartoœæ pola name, 
//albo 0, kiedy pole name jest ci¹giem pustym
void setgolf(golf & g);

//ustawia handicap gracza
void handicap(golf & g, int hc);

//wyœwietla zawartoœæ pól struktury golf
void showgolf(const golf & g);

Zauwa¿ ¿e funkcja setgolf() zosta³a przeci¹¿ona. Zastosowanie jej pierwszej wersji wygl¹da³oby
nastêpuj¹co:
golf ann;
setgolf(ann, "Ann Birdfree", 24);
Wywo³anie funkcji zawiera informacje umieszczane w polach struktury ann. W przypadku drugiej
wersji funkcji setgolf() wygl¹da³oby to raczej tak jak poni¿ej:
golf andy;
setgolf(andy);
Funkcjia samodzielnie zapyta u¿ytkownika programu o wartoœci dla pól struktury, odczyta je z wejœcia
i zapisze w polach struktury andy. Ta funkcja mog³aby (ale niekoniecznie) odwo³ywaæ siê wewnêtznie 
do pierwszej wersji funkcji.

Z³ó¿ na bazie takiego nag³ówka program wieloplikowy. Jeden z plików o nazwie golf.cpp
powinien zawieraæ definicje odpowiadaj¹ce prototypom z pliku nag³ówkowego. Drugi plik
powinien zawieraæ funkcjê main() i demonstrowaæ wszystkie mo¿liwoœci zastosowaniia funkcji 
prototypowanych w pliku nag³ówkowym. Mo¿esz na przyk³ad zastosowaæ pêtlê w której 
u¿ytkownik wprowadza³by dane dla tablicy struktur golf, przerywan¹ po wyczerpaniu tablicy
b¹dŸ wprowadzeniu w roli nazwiska gracza ci¹gu pustego. Do obs³ugi struktury golf funkcja
main() powinna stosowaæ jedynie funkcje prototypowane w pliku nag³ówkowym.
*/



int Chapter_9_Assignment1()
{
	std::cout << "\aFunction under construcion." << std::endl;
	const int arsize = 5;
	golf golfarray[arsize];
	char input[Len];
	int handicap=0;
	for (int i = 0; i < arsize; i++)
	{
		if (0==i%2)
		{
			setgolf(golfarray[i]);
			showgolf(golfarray[i]);
			continue;
		};
		std::cin.clear(); std::cin.ignore(1000, '\n');
		std::cout << "\nInput golf players:"
			<<"\nname: \t\t";
		std::cin.getline(input, Len, '\n');
		std::cin.clear(); std::cin.ignore(1000, '\n');
		std::cout << "handicap: \t";
		std::cin >> handicap;
		setgolf(golfarray[i], input, handicap);
		showgolf(golfarray[i]);
	};
	std::cout << "That were all of " << arsize << " players.\n"
		<< "Press any key to get back to menu...\n";
	_getch();
	return 0;
}

//date of creation: 18.08.2017
//Created by: Marcin Nowak