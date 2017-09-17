// Rozdzia³_5.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"


int RNG(int, int); //generating random numbers simulating input from user (not a part of course)


int RealNum_Range_Sum();
int Factorial_Array();
int Numbers_Adder();
int Investments();
int Book();
int Book_3years();
int Car_catalog();
int Word_couter();
int Word_Counter_String();
int Stars();

int RNG(int nbeginning, int nend)
{
	std::random_device Rand;
	std::mt19937 Twister(Rand());
	std::uniform_int_distribution<int> distribution(nbeginning, nend);
	return(distribution(Twister));
};



int RealNum_Range_Sum()
{
	std::cout << "Input 2 real numbers:\nnumber 1:";
	long int number1 = 0, number2 = 0, sum=0;
	std::cin >> number1;
	std::cout << "number 2: ";
	std::cin >> number2;
	for (long int i = number1; i <= number2; i++)
	 sum += i;
	std::cout << "Sum of <" << number1 << ", " << number2 << "> is " << sum;
	_getch();
	return 0;
};

int Factorial_Array()
{
	//5.4 using Array and using long double instead of long long, count 100!
	const int ArSize = 101;

	std::array<long double, ArSize> Factorial;
	Factorial[0] = Factorial[1] = 1;
	for (int i=2; i < ArSize; i++)
	{
		Factorial[i] = i*Factorial[i - 1];
	};
	for (int i = 0; i < ArSize; i++)
	{
		std::cout << "\n" << i << "!= " << Factorial[i];
	};
	_getch();
	return 0;
};

int Numbers_Adder()
{
	unsigned long long sum=0;
	char number;
	std::cout << "Function will sum all given numbers untill user inputs 0:\n";
	while ((number = std::cin.get()) != '0')
	{
		sum += (int)number;
	};
	std::cout << "Sum of all given numbers = " << sum;
	_getch();
	return 0;
};

int Investments()
{
	//Dafne earnings= 0.10 * beggining captial
	//Cleo earnings=0.05 * current capital
	//all counted yearly
	const int cibeginning_captial = 100;
	long double ldDafne = (0+cibeginning_captial), ldCleo = (0+cibeginning_captial);
	std::cout << "\nYear\tDafne\tCleo\n";
	for (int i = 1; ldCleo <= ldDafne; i++)
	{
		std::cout << i << "\t" << (ldDafne+=(0.10*cibeginning_captial)) << "\t" << (ldCleo += ldCleo * 0.05) << "\n";
	};
	_getch();
	return 0;
};

int Book()
{
	std::string smonth[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	int namounts[12]{}, nsum=0;
	std::cout << "Input amount of books sold each month:\n";
	for (int i = 0; i < 12; i++)
	{
		std::cout << smonth[i] << ": ";
		std::cin >> namounts[i];
		nsum += namounts[i];
	};
	std::cout << "Total amopunt of book sold: " << nsum;
	_getch();
	return 0;
};

int Book_3years()
{
	std::string smonth[3][12] = 
	{
		{ "January","February","March","April","May","June","July","August","September","October","November","December" }, 
		{ "January","February","March","April","May","June","July","August","September","October","November","December" },
		{ "January","February","March","April","May","June","July","August","September","October","November","December" }
	};
	int namounts[3][12]={}, nsum = 0;
	for (int j = 0; j < 3; j++)
	{
		std::cout << "\nYear " << j
				  <<"\nInput amount of books sold each month:\n";
		for (int i = 0; i < 12; i++)
		{
			std::cout << smonth[j][i] << ": ";
			//std::cin >> namounts[j][i];
			namounts[j][i] = RNG(150, 450);
			std::cout << namounts[j][i] << "\n";
			nsum += namounts[j][i];
		};
	}
	
	std::cout << "Total amopunt of book sold: " << nsum;
	_getch();
	return 0;
};

int Car_catalog()
{
	struct Car
	{
		std::string Name;
		unsigned int yearOfProduction;
	};
	Car *car_pointer;
	std::vector<Car *> vpointer_adress(0);
	std::cout << "How many cars would you like to catalog?:";
	unsigned int namount_of_cars = 0;
	std::cin >> namount_of_cars;


	for (unsigned int i =0; i <namount_of_cars; i++)
	{
		car_pointer = new Car;
		vpointer_adress.push_back(car_pointer);
		std::cin.clear(); std::cin.ignore(9999, '\n');
		std::cout << "Input producent: \t";
		std::getline(std::cin, (*car_pointer).Name);
		std::cout << "Input year of production: \t";
		std::cin >> (*car_pointer).yearOfProduction;
	};
	std::cout << "All catalogued cars: \n";
	for (unsigned int i = 0; i < namount_of_cars; i++)
	{
		std::cout << i << ":\t" << (vpointer_adress.at(i)->Name) << ",\t" << (vpointer_adress.at(i)->yearOfProduction) << "\n"; 
	}
	_getch();
	return 0;
};

int Word_couter()
{
	const char ccending_word[6] = "ready";
	const int arsize = 1000;
	char word[arsize]={};
	int namount_of_words = 0, nhlp=0;
	std::cout << "Input text which words you want to count (counting will end when '" << ccending_word << "'appeares as input):\n";
	for (int i = 0; i < arsize; i++)
	{
		std::cin.get(word[i]);
		nhlp += 1;
		if (word[i] == '\n')
		 break;
	};
	for (int i = 0; i < nhlp; i++)
	{
		char hlp[arsize] = {};
		int j = 0;
		while (!(word[i] == ' ' || word[i] == '\t' || word[i] == '\n' || word[i] == '\0'))
		{
			hlp[j] = word[i];
			i++, j++;
		};
		if (strcmp(hlp, ccending_word)==0) break;
		namount_of_words++;

	};
	std::cout << "\nAmount of words before '" << ccending_word << "' in given text: " << namount_of_words;
	_getch();
	return 0;
};

int Word_Counter_String()
{
	const std::string csending_word = "ready";
	std::string stext{}, swordcheck{};
	std::cout << "Input text which words you want to count (counting will end when '" << csending_word << "'appeares as input):\n";
	std::getline(std::cin, stext);
	int namount_of_words=0;
	for (unsigned int i = 0; i < stext.length() ; i++)
	{
		swordcheck.clear();
		for (size_t j = 0; j < stext.length(); j++, i++)
		{
			if (stext[i] == ' ') break;
			swordcheck[j] = stext[i];	
		};
		if (swordcheck == csending_word) break; 
		namount_of_words += 1;

	};
	std::cout << "\nAmount of words before '" << csending_word << "' in given text: " << namount_of_words;
	_getch();
	return 0;
};

int Stars()
{
	std::cout << "Input amount of stars you want to display on screen:";
	unsigned int namount_of_stars=0;
	std::cin >> namount_of_stars;
	for (unsigned int i = 0; i <= namount_of_stars; i++)
	{
		for (unsigned int j = namount_of_stars-i; j > 0; j--)
		{
			std::cout << ".";
		};
		for (unsigned int k = 0; k < i; k++)
		{
			std::cout << "*";
		};
		std::cout << std::endl;
	};
	_getch();
	return 0;
}

int Chapter_5()
{
	std::string options[]
	{ 
		"Assignment 1:\tSum of numbers in range",
		"Assignment 2:\tFactorial in array",
		"Assignment 3:\tAdd numbers untill '0'",
		"Assignment 4:\tInvestment calculator",
		"Assignment 5:\tBooks sold",
		"Assignment 6:\tBooks sold in 3 years",
		"Assignment 7:\tCatalog of cars",
		"Assignment 8:\tCounting input phrase words",
		"Assignment 9:\tCounting input phrase words - string",
		"Assignment 10:\tStar shenanigans"
	};
	int input;
	do
	{
		input = simplemenu(options, "Chapter 5");
		switch (input)
		{
		case 0: RealNum_Range_Sum(); break;
		case 1: Factorial_Array(); break;
		case 2: Numbers_Adder(); break;
		case 3: Investments(); break;
		case 4: Book(); break;
		case 5: Book_3years(); break;
		case 6: Car_catalog(); break;
		case 7: Word_couter(); break;
		case 8: Word_Counter_String(); break;
		case 9: Stars(); break;
		case 10: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != (sizeof(options) / sizeof(options[0])) - 1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 13.07.2017
//Created by: Marcin Nowak