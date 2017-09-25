#include "../stdafx.h"
#include "list.h"


List::~List()
{
	std::cout << "\n" << this << " list destroyed.\n";
}

bool List::AddItem(Item & value)
{
	End++;
	item[End] = value;
	return true;
}

bool List::isEmpty()
{
	if (End == 0) { return true;}
	else return false;
}

bool List::isFull() 
{
	if (End == maxelements) { return true; }
	else return false;
}


void List::visit(void(*pf)(Item &))
{
	pf(item[End]);
};