#include "../../stdafx.h"
#include "classic.h"

void Classic::Report() const
{
	Cd::Report();
	std::cout << "Primary work:\t" << primarywork << '\n';
};

Classic::Classic(const Classic & c) :Cd(c)
{
	strcpy_s(primarywork, c.primarywork);
}

Classic & Classic::operator=(const Classic & cl)
{
	if (&cl == this) {return *this;};
	this->Cd::operator=(cl);
	strcpy_s(primarywork, cl.primarywork);
	return *this;
};

//date of creation: 29.04.2017
//Created by: Marcin Nowak