#include "../stdafx.h"
#include "Chapter_7_Functions.h"

const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void display3(const student pa[], int n);

int Chapter_7_Assignment9()
{
	std::cout << "Assignment 9 :\n" << std::endl;
	std::cout << "Input amount of students in group: ";
	int class_size;
	std::cin >> class_size;
	while (std::cin.get() != '\n') continue;
	student *ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	};
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	std::cout << "Ready!\n";	
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
}


int getinfo(student pa[], int n)
{
	int amount=0;

	while (amount < n)
	{
		std::cout << "\nInput students name: ";
		std::cin >> pa[amount].fullname;
		if (0 == pa[amount].fullname) return amount;
		std::cout << "Input " << pa[amount].fullname << "s hobby: ";
		std::cin >> pa[amount].hobby;
		std::cout << "Input " << pa[amount].fullname << "s ooplevel: "; //TODO: oolevel ?!
		std::cin >> pa[amount].ooplevel;
		amount++;
	};
	return amount;
};

void display1(student st)
{
	std::cout << "\nStudent info:"
		<< "\nName:\t" << st.fullname
		<< "\nHobby:\t" << st.hobby
		<< "\nOOPlevel:\t" << st.ooplevel;
	return;
};

void display2(const student* ps)
{
	std::cout << "\nStudent "<< ps <<" info:"
		<< "\nName:\t" << (*ps).fullname
		<< "\nHobby:\t" << (*ps).hobby
		<< "\nOOPlevel:\t" << (*ps).ooplevel;
	return;
};

void display3(const student pa[], int n)
{
	std::cout << "\nInfo about " << n << " student/s:\n";
	for (int i = 0; i < n; i++, pa++)
	{
		std::cout << "#" << i+1 << "\n"
			<< "\nName:\t" << (*pa).fullname
			<< "\nHobby:\t" << (*pa).hobby
			<< "\nOOPlevel:\t" << (*pa).ooplevel << std::endl;
	};
	return;
};

//date of creation: 28.07.2017
//Created by: Marcin Nowak