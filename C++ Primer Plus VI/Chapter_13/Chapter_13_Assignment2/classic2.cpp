#include "../../stdafx.h"
#include "classic2.h"

namespace Cd2
{
	void Classic::Report() const
	{
		Cd::Report();
		std::cout << "Primary work:\t" << primarywork << '\n';
	};

	Classic::Classic(const Classic & c) :Cd(c)
	{
		primarywork = new char[strlen(c.primarywork)];
		std::strcpy(primarywork, c.primarywork);
	};

	Classic & Classic::operator=(const Classic & cl)
	{
		if (&cl == this) { return *this; };
		Cd::operator=(cl);
		//char * tempmemadress = primarywork;
		delete [] primarywork;	//this line causes memory leak & runtime error
		primarywork = new char[strlen(cl.primarywork)+1];
		std::strcpy(primarywork, cl.primarywork);
		//delete[] tempmemadress;	//Memory leak
		return *this;
	};

	Classic::~Classic()
	{
		delete [] primarywork;
	}
};
//date of creation: 01.05.2017
//Created by: Marcin Nowak