#include "../stdafx.h"
#include "Chapter_10_Functions.h"
#include "../Chapter_10/Account.h"


/*
1. Provide method definitions for the class described in Chapter Review Question 5
and write a short program that illustrates all the features.

Question:
5. Define a class to represent a bank account.Data members should include the
depositor’s name,the account number (use a string),and the balance.Member functions 
should allow the following: 
-Creating an object and initializing it. 
-Displaying the depositor’s name,account number,and balance 
-Depositing an amount of money given by an argument 
-Withdrawing an amount of money given by an argument 

Just show the class declaration,not the method implementations.
(Programming Exercise 1 provides you with an opportunity to write the implementation.)
*/


int Chapter_10_Assignment1()
{
	Account acc1{ "account1", "101010101010101010101010", 3000 };
	acc1.Display();
	acc1.Deposit(300);
	acc1.Display();
	acc1.Withdraw(1500);
	acc1.Display();
	acc1.~Account();
	std::cout << "\nPress any key to exit ..." << std::endl;
	_getch();
	return 0;
};

//date of creation: 26.08.2017
//Created by: Marcin Nowak