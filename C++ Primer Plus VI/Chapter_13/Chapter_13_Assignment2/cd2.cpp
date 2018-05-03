#include "../../stdafx.h"
#include "cd2.h"

namespace Cd2
{
	Cd::Cd(char* s1, char* s2, int n, double x)
	{
		performers = new char[strlen(s1) + 1];
		std::strcpy(performers, s1);
		label = new char[strlen(s2) + 1];
		std::strcpy(label, s2);
		selections = n;
		playtime = x;
	};

	Cd::Cd(const Cd & d)
	{
		char* tempperf = performers;
		char* templbl = label;
		
		performers = new char[strlen(d.performers) + 1];
		label = new char[strlen(d.performers) + 1];
		std::strcpy(performers, d.performers);
		std::strcpy(label, d.label);

		delete[] performers;
		delete[] label;
		selections = d.selections;
		playtime = d.playtime;
	};

	Cd::Cd()
	{
		performers = new char[1];
		label = new char[1];
		selections = 0;
		playtime = 0;
	};

	void Cd::Report() const
	{
		std::cout << this << " Cd:\n"
			<< "Performers:\t" << performers << '\n'
			<< "Label:\t\t" << label << '\n'
			<< "Selections:\t" << selections << '\n'
			<< "Playtime:\t" << playtime << '\n';
	};

	Cd & Cd::operator=(const Cd & d)
	{
		if (&d == this) { return *this; };
		
		delete[] performers;
		delete[] label;
		performers = new char[strlen(d.performers)+1];
		label = new char[strlen(d.label) + 1];
		
		std::strcpy(performers, d.performers);
		std::strcpy(label, d.label);
		selections = d.selections;
		playtime = d.playtime;
		return *this;
	};

	Cd::~Cd()
	{
		delete[] performers;
		delete[] label;
	};
}
//date of creation: 01.05.2017
//Created by: Marcin Nowak