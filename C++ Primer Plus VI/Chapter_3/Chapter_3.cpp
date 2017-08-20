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
void FuelLeft();	//TODO
void FuelUsage();

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

//TODO
void FuelLeft()
{
	/*
	6.Napisz program który bêdzie pyta³, ile mil przejechanoi ile galonów benzyny zu¿yto oraz il;e jeszcze zosta³o.
	Mo¿esz te¿ napisaæ program, który prosi o podanie odleg³oœci w kilometrach i iloœci benzyny w litrach,
	aby podaæ wynik zgodnie z normami europejskimi, w litrach na 100 kilometrów
	*/
	std::cout << "\aNothing to see here (YET), move along.\n"<< std::endl;
	_getch();
	return;
};

//TODO
void FuelUsage()
{
	std::cout << "\n\aFunction under construction, you enter at your own risk!\n" << std::endl;
	float usage;
	const double onehundredkilometresToMiles = 62.14, gallonToLitre = 3.8751;
	std::cout << "\nInput your fuel usage in liters per 100km:";
	std::cin >> usage;
		//convert it to american miles per galon, 100km=62,14mile 1gallon=3,875l
		//19mil na galon oznacza oko³o 12,4 l/100km, a 19mil na litrze to oko³o 12,4 l/100km, z kolei 27mil na godzinê to oko³o 0,7l/100km
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
		"Assignment 6:\tkm/liter on given gallons of fuel",
		"Assignment 7:\tFuel usage",
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
		case 5: FuelLeft(); break;
		case 6: FuelUsage(); break;		//TODO
		case 7: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != amountofoptions-1 && input != 27);
    return input;	//when ESC pressed as input
};

//date of creation: 06.07.2017
//Created by: Marcin Nowak