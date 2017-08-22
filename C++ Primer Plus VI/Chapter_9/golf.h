

const int Len = 40;
struct golf
{
	char fullname[Len];
	int handicap=0;
};


#ifndef SETGOLF_H
#define SETGOLF_H

//wersja nieinteraktywna
//funkcja ustawia w strukturze golf zadane nazwisko i handicap
//na podstawie argument�w wywo�ania
void setgolf(golf & g, const char * name, int hc);


//wersja interaktywna
// Funkcja pobiera nazwisko i warto�� handicapu od u�ytkownika
// i ustawia pola struktury g zgodnie z pobranymi warto�ciami;
// zwraca 1, je�li uda�o si� odczyta� z wej�cia warto�� pola name, 
//albo 0, kiedy pole name jest ci�giem pustym
void setgolf(golf & g);

#endif // !SETGOLF_H


//ustawia handicap gracza
#ifndef HANDICAP_H
#define HANDICAP_H

void handicap(golf & g, int hc);

#endif // !HANDICAP_H

//wy�wietla zawarto�� p�l struktury golf
#ifndef SHOWGOLF_H
#define SHOWGOLF_H

void showgolf(const golf & g);

#endif // !SHOWGOLF_H