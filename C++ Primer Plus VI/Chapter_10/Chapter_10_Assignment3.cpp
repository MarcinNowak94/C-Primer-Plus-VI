#include "../stdafx.h"
#include "Chapter_10_Functions.h"
#include "../Chapter_9/golf.h"

/*
3. Do Programming Exercise 1 from Chapter 9 but replace the code shown there with
an appropriate golf class declaration.Replace setgolf(golf &, const char*,
int) with a constructor with the appropriate argument for providing initial values.
Retain the interactive version of setgolf() but implement it by using the constructor.
(For example,for the code for setgolf(),obtain the data,pass the data to the
constructor to create a temporary object,and assign the temporary object to the
invoking object,which is *this.)

Chapter 9 assignment 1:
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

int Chapter_10_Assignment3()
{
	const int arsize = 5;
	Golf golfarray[arsize];
	for (size_t i = 0; i < arsize; i++)
	{
		if (i%2==0)
		{
			golfarray[i].Setgolf();
		} 
		else
		{
			golfarray[i] = Golf::Golf();
		};
	};

	for (size_t i = 0; i < arsize; i++)
	{
		std::cout << "\n\nGolf player #" << i + 1 << ": \n";
		golfarray[i].Showgolf();
	};
	std::cout << "\nThose were all " << arsize << " players.";
	_getch();
	return 0;
};

//date of creation: 26.08.2017
//Created by: Marcin Nowak