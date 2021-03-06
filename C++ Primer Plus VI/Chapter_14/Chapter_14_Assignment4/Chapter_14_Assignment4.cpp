#include "../Chapter_14_Functions.h"
#include "../../stdafx.h"

int Chapter_14_Assignment4()
{
	std::cout << "\nNothing to see here (YET). Move along."
		<< "\nPress any key to go back to menu...\n";
	_getch();
	return 0;
};

/*
A Person class holds the first name and the last name of a person.In addition to its
constructors,it has a Show() method that displays both names.A Gunslinger class
derives virtually from the Person class.It has a Draw() member that returns a type
double value representing a gunslinger�s draw time.The class also has an int
member representing the number of notches on a gunslinger�s gun.Finally,it has a
Show() function that displays all this information.

A PokerPlayer class derives virtually from the Person class.It has a Draw() member
that returns a random number in the range 1 through 52,representing a card value.
(Optionally,you could define a Card class with suit and face value members
and use a Card return value for Draw().) The PokerPlayer class uses the Person
show() function.The BadDude class derives publicly from the Gunslinger and
PokerPlayer classes.It has a Gdraw() member that returns a bad dude�s draw time
and a Cdraw() member that returns the next card drawn.It has an appropriate
Show() function.Define all these classes and methods,along with any other
necessary methods (such as methods for setting object values) and test them in a simple
program similar to that in Listing 14.12.
*/

//date of creation: 29.04.2017
//Created by: Marcin Nowak