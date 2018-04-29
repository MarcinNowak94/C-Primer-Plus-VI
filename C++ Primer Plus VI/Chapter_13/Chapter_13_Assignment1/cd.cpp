#include "../../stdafx.h"
#include "cd.h"

Cd::Cd(char* s1, char* s2, int n, double x)
{
	strcpy_s(performers, s1);
	strcpy_s(label, s2);
	selections = n;
	playtime = x;
};

Cd::Cd(const Cd & d)
{
	strcpy_s(performers, d.performers);
	strcpy_s(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
};

void Cd::Report() const
{
	std::cout << this << " Cd:\n"
		<< "Performers:\t" << performers << '\n'
		<< "Label:\t" << label << '\n'
		<< "Selections:\t" << selections << '\n'
		<< "Playtime:\t" << playtime << '\n';
};

Cd & Cd::operator=(const Cd & d)
{
	if (&d == this) { return *this; };
	strcpy_s(performers, d.performers);
	strcpy_s(label, d.label);
	this->selections = d.selections;
	this->playtime = d.playtime;
	return *this;
};

//date of creation: 29.04.2017
//Created by: Marcin Nowak