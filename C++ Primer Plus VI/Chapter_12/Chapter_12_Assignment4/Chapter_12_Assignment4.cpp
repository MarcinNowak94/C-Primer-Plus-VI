#include "../../stdafx.h"
#include "../Chapter_12_Functions.h"
#include "Stack_2.h"


int Chapter_12_Assignment4()
{
	std::cout << "\n\aNothing to see here (YET). Move along.";
	std::cout << "\nPress any key to continue ...";
	_getch();
	return 0;
};

/*
4. Consider the following variation of the Stack class defined in Listing 10.10:

// stack.h -- class declaration for the stack ADT 
typedef unsigned long Item;

class Stack
{
private:
	enum { MAX = 10 };      // constant specific to class 
	enum { MAX = 10 };      // constant specific to class 
	int size;             // number of elements in stack
	int size;             // number of elements in stack
public:
	Stack(int n = MAX);    // creates stack with n elements 
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full, true otherwise 
	bool push(const Item & item); // add item to stack
								  // pop() returns false if stack already is empty, true otherwise 
	bool pop(Item & item);  // pop top into item 
	Stack & operator=(const Stack & st);
};

As the private members suggest,this class uses a dynamically allocated array to hold
 the stack items.Rewrite the methods to fit this new representation and write a
program that demonstrates all the methods,including the copy constructor and 
assignment operator. 
*/