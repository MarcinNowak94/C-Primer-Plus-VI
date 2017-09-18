#include "../stdafx.h"
#include "Person.h"

Person::Person() { lname = ""; fname[0] = '\0'; };// #1

Person::Person(const std::string & ln, const char * fn)
{
	this->lname = ln;
	for (size_t i = 0; i < (sizeof(fn)/sizeof(fn[0]))+1; i++)
	{
		this->fname[i] = fn[i];
	};
};   // #2
															 
// the following methods display lname and fname
void Person::Show() const
{
	std::cout << fname << " " << lname;
};        // firstname lastname format

void Person::FormalShow() const
{
	std::cout << lname << " " << fname;
};  // lastname, firstname format