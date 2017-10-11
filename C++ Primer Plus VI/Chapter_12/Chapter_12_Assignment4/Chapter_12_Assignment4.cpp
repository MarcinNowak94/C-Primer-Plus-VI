#include "../../stdafx.h"
#include "../Chapter_12_Functions.h"
#include "Stack_2.h"


int Chapter_12_Assignment4()
{
	using namespace Stack_2;
	typedef unsigned long Item;
	const int arsize = 10;
	Item itemarr[10]{ random(),random(), random(), random(), random(), random(), random(), random(), random(), random() };
	Stack itemstack;
	std::cout << "Item array initialized with values:\n";
	for (size_t i = 0; i < arsize; i++)
	{
		std::cout << "Item array element #" << i << ": " << itemarr[i] << '\n';
		
	};
	std::cout << "\n\nPushing Item array to itemstack "<< &itemstack << ":\n";
	for (size_t i = 0; i < arsize; i++)
	{
		//std::cout << "Item array alement #" << i << ": " << itemarr[i] << '\n';
		itemstack.push(itemarr[i]);
	};
	Stack anotherstack = itemstack;
	std::cout << "\n\nCopy of itemstack " << &itemstack << " saved in anotherstack" << &anotherstack << ".\n";
	std::cout << "\nPopping items from itemstack " << &itemstack << ":\n";
	for (size_t i = 0; i < arsize; i++)
	{
		itemstack.pop(itemarr[i]);
	};
	std::cout << "\n\nAssigning some item array elements boack to itemstack " << &itemstack <<":\n";
	for (size_t i = 0; i < random(2, 7); i++)
	{
		itemstack.push(itemarr[i]);
	};
	std::cout << "\n\nLet's take a look at  anotherstack " << &anotherstack << " then:\n";
	size_t i = 0;
	while (!anotherstack.isempty())
	{
		anotherstack.pop(itemarr[i++]);
	};
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