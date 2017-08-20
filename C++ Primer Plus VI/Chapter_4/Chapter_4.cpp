// Rozdzia³_4.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"


void Metric();
void Listing4_4using_string();
int One_writing();
int One_writing_string();
int Snack();
int Snack_Array();
int William_Pizza_Metric();
int New_William_Pizza_Metric();
int Dynamic_Snack_Array();
int Hundred_Meter_Dash();

void Metric()
{
	std::cout << "What is your name?:";
	std::string sname;
	std::getline(std::cin, sname);
	std::cout << "What is your surname?:";
	std::string ssurname;
	std::getline(std::cin, ssurname);
	std::cout << "What mark(2-6) do you deserve?:";
	unsigned int uimark;
	std::cin >> uimark;
	std::cout << "How old are you?:";
	unsigned int uiage;
	std::cin >> uiage;
	std::cout << "\n-----------------------------------------\n"
		<< "Name: " << ssurname << ", " << sname << "\n"
		<< "Mark: " << uimark - 1 << "\n"
		<< "Age: " << uiage << std::endl;
	_getch();
	return;
};

void Listing4_4using_string()
{
	std::string sname = "", sdessert = "";
	std::cout << "What is your name?:\n";
	getline(std::cin, sname);
	std::cout << "What dessert do you like the most?:\n";
	getline(std::cin, sdessert);
	std::cout << "\nI have " << sdessert << " for " << sname << "\n";
	_getch();
	return;
};

int One_writing()
{
	std::cout << "Input your name: ";
	char cname[80] =" ";
	std::cin.getline(cname, 80);
	std::cout << "\nInput your surname: ";
	char csurname[80] =" ";
	std::cin >> csurname;
	char ccombined[160]=" ";
	std::strcpy(ccombined, cname);			//copies content of cname to ccombined
	std::strcat(ccombined, ", ");			// adds specified characters to ccombined
	std::strcat(ccombined, csurname);		//  -----||-----
	std::cout << "Here are all the infrmations displayed as continuous text : "
		<< ccombined << "\n";
	_getch();
	return 0;
};

int One_writing_string()
{
	std::cout << "Input your name: ";
	std::string sname = "";
	getline(std::cin, sname);
	std::cout << "\nInput your surname: ";
	std::string ssurname = "";
	getline(std::cin, ssurname);
	std::string scombined = "";
	scombined = sname + ", " + ssurname + "\0";
	std::cout << "Here are all the infrmations displayed as continuous text : "
		<< scombined << "\n";
	_getch();
	return 0;
};

int Snack()
{
	struct Batonik
	{
		std::string sbrand;
		double dweight;
		unsigned int uiamountOfCalories;
	};
	Batonik snack{ "Mocha Munch", 2.3, 350 };
	std::cout << "Structure Batonik contains 1 member:\n"
		<< snack.sbrand << ", weighing: " << snack.dweight << "g, containing: " << snack.uiamountOfCalories << "cal.\n" << std::endl;
	_getch();
	return 0;
};

int Snack_Array()
{
	struct Batonik
	{
		std::string sbrand;
		double dweight;
		unsigned int uiamountOfCalories;
	};

	Batonik snacks[3];
	
	snacks[0] = { "Snickers", 30.5 , 300 };
	snacks[1] = { "Mars", 28.6 , 289 };
	snacks[2] = { "Milky Way", 15, 180 };

	for (int i = 0; i < 3; i++)
	{
		std::cout << "\nSnack[" << i << "]: \n"
			<< "Brand: " << snacks[i].sbrand
			<< "\nWeight: " << snacks[i].dweight
			<< "\nCalories: " << snacks[i].uiamountOfCalories;
	};
	_getch();
	return 0;
};

int William_Pizza_Metric()
{
	struct Pizza
	{
		std::string sbrand;
		double ddiameter;
		double dweight;
	};
	Pizza newBrand;
	std::cout << "Input brand name:";
	getline(std::cin, newBrand.sbrand);
	std::cout << "Iput diameter(separated by dot):";
	std::cin >> newBrand.ddiameter;
	std::cout << "Input weight (separated by dot):";
	std::cin >> newBrand.dweight;
	std::cout << "\nNew pizza brand: \"" << newBrand.sbrand << "\", diameter " << newBrand.ddiameter << ", weighing " << newBrand.dweight << ".\n";
	_getch();
	return 0;
};

int New_William_Pizza_Metric()
{
	struct Pizza
	{
		std::string sbrand;
		double ddiameter;
		double dweight;
	};
	Pizza * newBrandpointer;
	newBrandpointer = new Pizza;
	std::cout << "Iput diameter(separated by dot):";
	std::cin >> (*newBrandpointer).ddiameter;
	std::cin.get();
	std::cout << "Input brand name:";
	getline(std::cin, (*newBrandpointer).sbrand);
	std::cout << "Input weight (separated by dot):";
	std::cin >> (*newBrandpointer).dweight;
	std::cout << "\nNew pizza brand: \"" << (*newBrandpointer).sbrand << "\", diameter " << (*newBrandpointer).ddiameter << ", weighing " << (*newBrandpointer).dweight << ". All this at location: " << &newBrandpointer << ".\n";

	_getch();
	return 0;
}; 

int Dynamic_Snack_Array()
{
	struct Batonik
	{
		std::string sbrand;
		double dweight;
		unsigned int uiamountOfCalories;
	};

	Batonik * pointer[3] = { new Batonik, new Batonik, new Batonik };

	pointer[0]->sbrand = "Snickers";			//first way of doing it
	pointer[0]->dweight = 30.5;
	pointer[0]->uiamountOfCalories = 300;

	(*pointer[1]).sbrand = "Mars";				//second way of doing it
	(*pointer[1]).dweight = 28.6;
	(*pointer[1]).uiamountOfCalories = 289;

	(*pointer[2]).sbrand = "Milky Way";
	(*pointer[2]).dweight = 15;
	(*pointer[2]).uiamountOfCalories = 180;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "\nSnack[" << i << "]: \n"
			<< "Brand: " << pointer[i]->sbrand
			<< "\nWeight: " << (*pointer[i]).dweight
			<< "\nCalories: " << (*pointer[i]).uiamountOfCalories;
	};
	_getch();
	return 0;
};

int Hundred_Meter_Dash()
{
	std::array<double, 3> times{};
	std::cout << "Input your 3 100 metre dash times:\n"
		<< "Time 1: ";
	std::cin >> times[0];
	std::cout << "Time 2: ";
	std::cin >> times[1];
	std::cout << "Time 3: ";
	std::cin >> times[2];
	std::cout << "Your average time is :" << (times[0] + times[1] + times[2]) / 3 << "seconds\n";
	_getch();
	return 0;
};


int Chapter_4()
{
	std::string options[]
	{ 
		"Assignment 1:\tGrade yourself",
		"Assignment 2:\tListing 4.4 using srting",
		"Assignment 3:\tConcatenating chars",
		"Assignment 4:\tConcatenating strings",
		"Assignment 5:\tSnack",
		"Assignment 6:\tArray of Snacks",
		"Assignment 7:\tWilliam's Pizza Metric",
		"Assignment 8:\tDynamic William's Pizza Metric",
		"Assignment 9:\tDynamic Snack array",
		"Assignment 10:\tAverage hundred meter dash score",
		"Back"
	};
	const int amountofoptions = 11;
	int input;
	do
	{
		input = simplemenu(options, amountofoptions);
		switch (input)
		{
		case 0: Metric(); break;
		case 1: Listing4_4using_string(); break;
		case 2: One_writing(); break;
		case 3: One_writing_string(); break;
		case 4: Snack(); break;
		case 5: Snack_Array(); break;
		case 6: William_Pizza_Metric(); break;
		case 7: New_William_Pizza_Metric(); break;
		case 8: Dynamic_Snack_Array(); break;
		case 9: Hundred_Meter_Dash(); break;
		case 10: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != amountofoptions-1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 11.07.2017
//Created by: Marcin Nowak