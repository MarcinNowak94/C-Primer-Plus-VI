#pragma once
#ifndef C12_A4_STACK_H
#define C12_A4_STACK_H

namespace C12_A4
{
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

}

#endif // !C12_A3_STACK_H