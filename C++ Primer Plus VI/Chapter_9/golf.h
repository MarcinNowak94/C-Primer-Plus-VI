

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
//na podstawie argumentów wywo³ania
void setgolf(golf & g, const char * name, int hc);


//wersja interaktywna
// Funkcja pobiera nazwisko i wartoœæ handicapu od u¿ytkownika
// i ustawia pola struktury g zgodnie z pobranymi wartoœciami;
// zwraca 1, jeœli uda³o siê odczytaæ z wejœcia wartoœæ pola name, 
//albo 0, kiedy pole name jest ci¹giem pustym
void setgolf(golf & g);

#endif // !SETGOLF_H


//ustawia handicap gracza
#ifndef HANDICAP_H
#define HANDICAP_H

void handicap(golf & g, int hc);

#endif // !HANDICAP_H

//wyœwietla zawartoœæ pól struktury golf
#ifndef SHOWGOLF_H
#define SHOWGOLF_H

void showgolf(const golf & g);

#endif // !SHOWGOLF_H

//CHAPTER 10 ASSIGNMENT 3

#ifndef GOLF_H
#define GOLF_H

class Golf
{
public:
	Golf(char name[]="default player", int handicap=10 );
	~Golf();
	void Setgolf();
	void Showgolf();

private:
	static const int m_Len = 40;
	char m_fullname[m_Len];
	int m_handicap;
};

#endif // !GOLF_H
