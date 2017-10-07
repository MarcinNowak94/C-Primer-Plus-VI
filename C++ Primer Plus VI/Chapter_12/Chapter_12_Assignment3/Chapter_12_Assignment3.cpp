#include "../../stdafx.h"
#include "../Chapter_12_Functions.h"
#include "stock20.h"

const int STKS = 4;
int usestock20()
{
	// utwórz tablicê zainicjalizowanych obiektów
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("BurakPOL", 200, 2.0),
		Stock("GruzPOL", 130, 3.25),
		Stock("FutroPOL", 60, 6.5)
	};

	std::cout << "Portfel inwestycyjny:\n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();
	// ustawienie wskaŸnika na pierwszy element
	const Stock * top = &stocks[0];
	for (st = 0; st < STKS; st++)
		top = &top->topval(stocks[st]);
	// teraz top wskazuje do najbardziej wartoœciowych udzia³ów w portfelu
	std::cout << "\nNajbardziej wartoœciowy pakiet:\n";
	top->show();
	return 0;
}


int Chapter_12_Assignment3()
{
	std::cout << "\n\aNothing to see here (YET). Move along.";
	std::cout << "\nPress any key to continue ...";
	usestock20();
	_getch();
	return 0;
};

/*
3. Rewrite the Stock class,as described in Listings 10.7 and 10.8 in Chapter 10 so
that it uses dynamically allocated memory directly instead of using string class
objects to hold the stock names.Also replace the show() member function with an
overloaded operator<<() definition.Test the new definition program in Listing
10.9.
*/