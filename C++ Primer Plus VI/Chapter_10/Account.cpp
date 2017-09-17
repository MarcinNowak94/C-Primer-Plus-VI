#include "../stdafx.h"
#include "../Chapter_10/Account.h"

Account::Account(const std::string name, const std::string number, const long long balance)
{
	this->m_name = name;
	this->m_number = number;
	this->m_balance = balance;
};

void Account::Display()
{
	std::cout << "\nDepositors name :" << this->m_name
		<< "\nAccount #: " << this->m_number
		<< "\nBalance : " << this->m_balance;
};

void Account::Deposit(const int amount)
{
	this->m_balance += amount;
};

void Account::Withdraw(const int amount)
{
	this->m_balance -= amount;
};

Account::~Account()
{
	std::cout << "\t\aAccount #" << this->m_number << " closed.";
};