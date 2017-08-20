#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"

int Eeny();
int Miny();
float CelsiusToFahrenheit(int celsius);
double LightyearsToAU(double lightyear);
void TimeDisplay(unsigned short hours, unsigned short minutes);

int Chapter_assignment1();
int Chapter_assignment2();
int Chapter_assignment3();
int Chapter_assignment4();
int Chapter_assignment5();
int Chapter_assignment6();
int Chapter_assignment7();

int Chapter_2()
{
	std::string options[]
	{
		"Assignment 1:\tDisplay author",
		"Assignment 2:\tNautical miles to metres",
		"Assignment 3:\tEeny, meeny, miny, moe",
		"Assignment 4:\tYears to months",
		"Assignment 5:\tCelsius to Fahrenheit",
		"Assignment 6:\tLight years to astronomical units",
		"Assignment 7:\tShow time",
		"Back to main menu"
	};
	const int amountofoptions = 8;
	int input;
	do
	{
		input = simplemenu(options, amountofoptions);
		switch (input)
		{
		case 0: Chapter_assignment1(); break;
		case 1: Chapter_assignment2(); break;
		case 2: Chapter_assignment3(); break;
		case 3: Chapter_assignment4(); break;
		case 4: Chapter_assignment5(); break;
		case 5: Chapter_assignment6(); break;
		case 6: Chapter_assignment7(); break;
		case 7: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != amountofoptions - 1 && input != 27);
	return input;	//when ESC pressed as input
}

int Eeny()
{
	std::cout << "Eeny, meeny \n";
	return 0;
};

int Miny()
{
	std::cout << "miny, mope.\n";
	return 0;
};

float CelsiusToFahrenheit(int celsius)
{
	const float fahrenheittocelsiusratio = 1.8;
	return((celsius*fahrenheittocelsiusratio) + 32);
};

double LightyearsToAU(double lightyear)
{
	const double lightyeartokilometre = 150000000;
	const double kilometreminlightyear = 10000000000;
	return ((lightyear*lightyeartokilometre) / kilometreminlightyear);
};

void TimeDisplay(unsigned short hours, unsigned short minutes)
{
	std::cout << "\n" << hours << ":" << minutes << std::endl;
	return;
};


int Chapter_assignment1()
{
	std::cout << "\nAuthor: Marcin Nowak" << std::endl;
	_getch();
	return 0;
};

int Chapter_assignment2()
{
	std::cout << "\nInput amount of nautical miles:";
	const int nauticalmilestometres = 1852;	
	long int amountofmiles;
	std::cin >> amountofmiles;
	std::cout << amountofmiles << " equals to " << amountofmiles*nauticalmilestometres << " metres.\n"
		<< "Press any key to continue ..." << std::endl;
	_getch();
	return 0;
};

int Chapter_assignment3()
{
	Eeny();
	Eeny();
	Miny();
	Miny();
	std::cout << "Press any key to continue..." << std::endl;
	_getch();
	return 0;
};

int Chapter_assignment4()
{
	std::cout << "\nHow old are you?:";
	unsigned int age = 0;
	std::cin >> age;
	std::cout << "If you trulty are " << age << " year/s old, that memans you are living for " << age * 12 << " months.\n"
		<< "Press any key to continue ..." << std::endl;
	_getch();
	return 0;
};

int Chapter_assignment5()
{
	std::cout << "Input temperature in Celsius degrees:";
	int temperature = 0;
	std::cin >> temperature;
	std::cout << temperature << "degree/s Celcius is " << CelsiusToFahrenheit(temperature) << " Fahrenheit.\n"
		<< "Press any key to continue..." << std::endl;
	_getch();
	return 0;
};

int Chapter_assignment6()
{
	/*
	AU=~150 000 000 km
	lightyear ~10 000 000 000km/y
	4.2ly=265608AU
	*/
	std::cout << "Input amount of lightyears:";
	double lightyears = 0;
	std::cin >> lightyears;
	std::cout << lightyears << " lightyears = " << LightyearsToAU(lightyears) << " astronomical units.\n"
		<< "Press any key to continue...\n" << std::endl;
	_getch();
	return 0;
};

int Chapter_assignment7()
{
	std::cout << "Input amount of hours: ";
	unsigned short hour = 0;
	std::cin >> hour;
	std::cout << "Input amount of minutes: ";
	unsigned short minute = 0;
	std::cin >> minute;
	TimeDisplay(hour, minute);
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return 0;
};

//date of creation: 18.08.2017
//Created by: Marcin Nowak