#include "../stdafx.h"
#include "../Chapter_9/golf.h"

Golf::Golf(char name[], int handicap)
{
	for (size_t i = 0; i < std::strlen(name); i++)
	{
		this->m_fullname[i] = name[i];
	};
	this->m_fullname[std::strlen(name)] = NULL;
	this->m_handicap = handicap;
}

Golf::~Golf()
{
	//std::cout << this->m_fullname << " record destructed\n";
};

void Golf::Setgolf()
{
	int iterator = 0, handicap = 0;
	char helper[Golf::m_Len];
	std::cin.clear(); std::cin.ignore(1000, '\n');
	std::cout << "\nInput golf players:\n"
		<< "name: \t\t";
	helper[iterator] = std::cin.get();
	while (helper[iterator] != '\n')
	{
		helper[++iterator] = std::cin.get();
	};
	helper[iterator++] = NULL;
	std::cin.clear(); std::cin.ignore(1000, '\n');
	std::cout << "handicap: \t";
	std::cin >> handicap;
	*this = Golf::Golf(helper, handicap);
};

void Golf::Showgolf()
{
	std::cout << "Name: " << this->m_fullname
		<< "\nHandicap: " << this->m_handicap;
};