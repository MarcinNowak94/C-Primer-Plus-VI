#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
	std::string m_name;
	std::string m_number;
	long long m_balance;
public:
	Account(const std::string name, const std::string number, const long long balance);
	void Display();
	void Deposit(const int amount);
	void Withdraw(const int amount);
	~Account();
};

#endif