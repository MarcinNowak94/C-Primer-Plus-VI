#include "../../stdafx.h"
#include "Stack_2.h"

Stack_2::Stack::Stack(int n)
{
	this->pitems = new Item[n];
	this->top = 0;
	this->size = 0;
	std::cout << "\n" << this << " default constructor\n";
}; 

Stack_2::Stack::Stack(const Stack & st)
{
	/*
	Stack temp;
	std::cout << "\n\acopy constructor temp: " << &temp << "\n";
	for (size_t i = 0; i < st.size; i++)
	{
		temp.top++;
		temp.size++;
		temp.pitems[i] = st.pitems[i];
	};*/
	std::cout << "\n\acopy constructor " << this << "\n";
	this->pitems = new Item[st.size];
	this->top = 0;
	this->size = 0;
	for (size_t i = 0; i < st.size; i++)
	{
		this->top++;
		this->size++;
		this->pitems[i] = st.pitems[i];
	};
};

Stack_2::Stack::~Stack() 
{
	std::cout << "\nDeleting " << this << " " << this->pitems <<'\n';
	
	delete [] pitems;			//error to fix
};

bool Stack_2::Stack::isempty() const
{
	return this->top == 0 ? true : false;
};

bool Stack_2::Stack::isfull() const
{
	return this->top == MAX ? true : false;
};			
// push() returns false if stack already is full, true otherwise 
bool Stack_2::Stack::push(const Item & item)
{
	if (this->size == MAX) return false;
	this->top++;
	this->size++;
	this->pitems[top] = item;
	std::cout << "\nItem " << item << " added to stack at " << &(this->pitems[top]) << ".";
	return true;
	
};	// add item to stack 

//pop() returns false if stack already is empty, true otherwise 
bool Stack_2::Stack::pop(Item & item)
{
	if (this->size == 0) return false;
	std::cout << "\nItem " << item << " popped from stack at " << &(this->pitems[top]) << ".";
	item=this->pitems[this->top];
	this->pitems[this->top] = 0;
	this->top--;
	this->size--;
	return true;
};			// pop top into item 

Stack_2::Stack & Stack_2::Stack::operator=(const Stack & st)
{
	//deep copy
	Stack temp;
	for (size_t i = 0; i < st.size; i++)
	{
		temp.top++;
		temp.size++;
		temp.pitems[i] = st.pitems[i];
	};
	return temp;
};