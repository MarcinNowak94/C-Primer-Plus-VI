#include "../stdafx.h"
#include "Plorg.h"

Plorg::Plorg(char* name, int Contentment)
{
	for (size_t i = 0; i< strlen(name); i++)
	{
		this->m_name[i] = name[i];
	};
	this->m_name[strlen(name)] = NULL;
	this->m_CI = Contentment;
	return;
};

void Plorg::updateCI()
{
	std::cout << "Update Contentment Indef of " << this->m_name << " plorg by (input amount):";
	int contentment = 0;
	std::cin >> contentment;
	this->m_CI += contentment;
	return;
};

void Plorg::Report(char* name, int CI)
{
	std::cout << "Plorg " << this->m_name << " changed to ";
	for (size_t i = 0; i< strlen(name); i++)
	{
		this->m_name[i] = name[i];
	};
	this->m_name[strlen(name)] = NULL;
	std::cout << this->m_name << "."
		<< "\n" << this->m_name << " contentment index updated to " << (this->m_CI=CI);
	return;
}

void Plorg::Display()
{
	std::cout << "\nName:\t\t" << this->m_name
		<< "\nContentment:\t" << this->m_CI;
	return;
}

Plorg::~Plorg()
{
	std::cout << this->m_name << " could not take it anymore."
		<< "\n" << this->m_name << " left. Farewell!";
}