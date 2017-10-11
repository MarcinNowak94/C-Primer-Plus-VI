#pragma once
#ifndef STACK_2_H
#define STACK_2_H

namespace Stack_2
{
	typedef unsigned long Item;
	class Stack
	{
	private:
		enum { MAX = 10 };				// constant specific to class 
		Item  * pitems;					// holds stack items 
		int size;						// number of elements in stack 
		int top;						// index for top stack item 

	public:
		Stack(int n = MAX);				// creates stack with n elements 
		Stack(const Stack & st);
		~Stack();
		bool isempty() const;
		bool isfull() const;			// push() returns false if stack already is full, true otherwise 
		bool push(const Item & item);	// add item to stack 
										//pop() returns false if stack already is empty, true otherwise 
		bool pop(Item & item);			// pop top into item 
		Stack & operator=(const Stack & st);
	};

};

/*As the private members suggest,this class uses a dynamically allocated array to hold
 the stack items.Rewrite the methods to fit this new representation and write a
program that demonstrates all the methods,including the copy constructor and 
assignment operator. */

#endif // !STACK_H