#include "../stdafx.h"
#include "Chapter_10_Functions.h"
#include "Move.h"

/*
6.Here’s a class declaration:
class Move
{
private:
double x;
double y;
public:
Move(double a = 0, double b = 0);   // sets x, y to a, b
showmove() const;                   // shows current x, y values
Move add(const Move & m) const;
// this function adds x of m to x of invoking object to get new x,
// adds y of m to y of invoking object to get new y, creates a new
// move object initialized to new x, y values and returns it
reset(double a = 0, double b = 0);  // resets x,y to a, b
};
Create member function definitions and a program that exercises the class.
*/

int Chapter_10_Assignment6()
{
	Move first;
	Move second(2, 5);
	std::cout << "\nInitially:";
	first.Showmove();
	std::cout << "\nInitially ";
	second.Showmove();
	Move third(first.add(second));
	std::cout << "\nObject "<< &third << " created via adding " << &second << " to " << &first << ": ";
	third.Showmove();
	second.Showmove();
	std::cout << "\nResetting " << &second;
	second.reset();
	std::cout << "\nAfter reset " << &second << " :";
	second.Showmove();
	std::cout << "\nPress Any key to continue...";
	_getch();
	return 0;
};

//date of creation: 26.08.2017
//Created by: Marcin Nowak