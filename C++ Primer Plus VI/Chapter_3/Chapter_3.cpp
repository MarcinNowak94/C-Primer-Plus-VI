// Rozdzia³ 3.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//1feet = 30,48 cm; 1inch = 2,54cm; 1feet=12inches;

#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"

void Height();
void Imperial_BMI();
void Longitude();
void Time();
void Population();
void FuelUsage();
void FuelConsumption();

void Height()
{
	const double feetToCmratio = 30.14, inchToCmRatio = 2.54;
	double centymetres = 0, feet = 0, inches = 0;
	std::cout << "\nSpecify your height in centimetres: ";
	 do
	 {
		 std::cin.sync(); std::cin.clear();
		 std::cin >>centymetres;
	 } while (!std::cin.good());
	 feet = centymetres / feetToCmratio;
	 centymetres = centymetres - (feet*feetToCmratio);
	 inches = centymetres / inchToCmRatio;
	 std::cout << "\nYour height in imperial units is: " << feet << " feet " << inches << " inches.";
	 _getch();
	 return;
}

void Imperial_BMI()
{
	const int feetToInches = 12;
	const float inchesToMetres = 0.0254, poundsToKilograms = 2.2;
	int feet, inches;
	float pounds, metres, kilograms;
	pounds = feet = inches = metres = kilograms = 0;
	std::cout << "Specify your dimensions in:\n"
		<< "Height(feet<space>inches): ";
		std::cin >> feet;
		std::cin >> inches;
	std::cout << "Weight(pounds): ";
		std::cin >> pounds;

	metres = (inches+(feet*feetToInches))*inchesToMetres;
	kilograms = pounds/poundsToKilograms;
	std::cout << feet << "ft "<<inches << "in " << pounds << "pnds " << metres << "m " << kilograms << "kg " <<std::endl;
	std::cout << "\nYour BMI is " << kilograms / (metres*metres) << " .\n";
	_getch();
	return;
}

void Longitude()
{
	static int secondsToMinute = 60, minutesToDegrees = 60;
	int degrees, minutes, seconds;
	long double dgrs;
	dgrs = degrees = minutes = seconds = 0;
	std::cout << "\nInput longitude in degrees, minutes and seconds(separated by one space each):";
	std::cin >> degrees; std::cin >> minutes; std::cin >> seconds;
	dgrs = degrees + ((static_cast<long double>(minutes) + (static_cast<long double>(seconds) / secondsToMinute)) / minutesToDegrees);
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);						//setting accuracy of displayed numbers
	std::cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = " << dgrs << " degrees.";
	_getch();
	return;

}

void Time()
{
	const int HoursInDay = 24, MinutesInHour = 60, SecondsInMinute = 60;
	long long seconds;
	std::cout << "\nInput amount of seconds: ";
	std::cin >> seconds;
	std::cout << seconds << " seconds = " << seconds / (HoursInDay*MinutesInHour*SecondsInMinute) << " days, "
		<< (seconds % (HoursInDay*MinutesInHour*SecondsInMinute))/ (MinutesInHour*SecondsInMinute) << " hours, "
		<< ((seconds % (HoursInDay*MinutesInHour*SecondsInMinute))% (MinutesInHour*SecondsInMinute))/SecondsInMinute << " minutes, "
		<< ((seconds % (HoursInDay*MinutesInHour*SecondsInMinute)) % (MinutesInHour*SecondsInMinute))% SecondsInMinute <<" seconds.";
	_getch();
	return;
};

void Population()
{
	std::string countryName;
	unsigned long long int world_population, country_population;
	long double populationPercent = 0;
	std::cout << "What country do you live in ?";
	std::getline(std::cin, countryName);
	//countryName = "Poland";
	std::cout << "Input current world population: \t";
	std::cin >> world_population;
	//ullworld_population = 6898758899;
	std::cout << "Input " << countryName.c_str() << " population: \t\t";
	std::cin >> country_population;
	//ullcountry_population = 38482919;
	populationPercent = (static_cast<long double>(country_population) * 100) / static_cast<long double>(world_population);
		std::cout << "Population of " << countryName.c_str() << " is " << populationPercent << "% of the world population.\n";
	_getch();
	return;
};

void FuelUsage()
{
	/*
	Original:
	Write a program that asks how many miles you have driven and how many gallons of gasoline you have used
	and then reports the miles per gallon your car has gotten. Or,if you prefer,the program can request
	distance in kilometers and petrol in liters and then report the result European style,in liters per 100 kilometers.
	*/
	std::cout << "\n[m]for metric, [i] for imperial"
		<< "\nFuel usage calculator - pick system: ";
	char choice = ' ';
	do
	{
		std::cin >> choice;
	} while (choice!='m' && choice!='M' && choice!='i' && choice!='I');
	switch (choice)
	{
		case 'i': case 'I':
		{
			std::cout << "\nHow many miles have you driven? :";
			float miles = 0;
			std::cin >> miles;
			std::cout << "\nHow many gallons of gasoline was used? :";
			float gallons = 0;
			std::cin >> gallons;
			std::cout << "\nYour car fuel usage is " << miles/gallons << " mi/gal.\n";
			std::cout << "\nPress any key to exit..." << std::endl;
		}; break;
		case 'm': case 'M':
		{
			std::cout << "\nHow many kilometers have you driven? :";
			float kilometers = 0;
			std::cin >> kilometers;
			std::cout << "\nHow many liters of gasoline was used? :";
			float liters = 0;
			std::cin >> liters;
			std::cout << "\nYour car fuel usage is " << liters/ kilometers << " l/km.\n";
			std::cout << "\nPress any key to exit..." << std::endl;
		}; break;
		default: {std::cout << "\n\aSomething had to go wrong.\nPress any key to continue..."; _getch(); return; }; break;
	};
	_getch();
	return;
};

void FuelConsumption()
{
	/*
	Original:
	Write a program that asks you to enter an automobile gasoline consumption figure in the European style 
	(liters per 100 kilometers) and converts to the U.S.style of miles per gallon. Note that in addition to using
	different units of measurement,the U.S. approach (distance / fuel) is the inverse of the European approach (fuel / distance).
	Note that 100 kilometers is 62.14 miles,and 1 gallon is 3.875 liters. 
	Thus,19 mpg is about 12.4 l/100 km,and 27 mpg is about 8.7 l/100 km
	*/
	float milesper100km = 62.14;
	float literspergallon = 3.875;
	const double onehundredkilometresToMiles = 62.14, gallonToLitre = 3.8751;
	std::cout << "\nInput your fuel usage in liters per 100km: _____ l/km\b\b\b\b\b\b\b\b\b\b";
	float usage=0;
	std::cin >> usage;
	std::cout << "\nThis is equivalent to " << milesper100km/(usage/literspergallon)<< " miles per gallon in imperial units."
		<< "\nPress any key to continue..." << std::endl;
	_getch();
};

int Chapter_3()
{
	std::string options[]
	{
		"Assignment 1:\tHeight converter",
		"Assignment 2:\tBMI in imperial units",
		"Assignment 3:\tLongitude in degrees",
		"Assignment 4:\tSeconds to time",
		"Assignment 5:\tCountry percentage of world population",
		"Assignment 6:\tFuel usage calculator",
		"Assignment 7:\tFuel consumption",
		"Back to main menu" 
	};
	const int amountofoptions = 8;
	int input;
	do
	{
		input = simplemenu(options, amountofoptions);
		switch (input)
		{
		case 0: Height(); break;
		case 1: Imperial_BMI(); break;
		case 2: Longitude(); break;
		case 3: Time(); break;
		case 4: Population(); break;
		case 5: FuelUsage(); break;
		case 6: FuelConsumption(); break;
		case 7: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != amountofoptions-1 && input != 27);
    return input;	//when ESC pressed as input
};

//date of creation: 06.07.2017
//Created by: Marcin Nowak