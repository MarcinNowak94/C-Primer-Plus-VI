// Rozdzial_6.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include <cctype>
#include "../stdafx.h"
#include "../chapters.h"
#include "../simplemenu.h"

int low_to_UP();
int Contributions();
int Menu();
int Good_Will_Programmers();
int Naturland();
int Sponsors();
int Word_calculator();
int File_character_counter();
int File_sponsors();

int low_to_UP()
{
	std::cout << "Input text which letter would you like to switch (UPPER to lower and lower to  UPPER), @ ends sequence\n";
	std::string character;
	std::getline(std::cin, character);
	int  i = 0;
	while ('@' != character[i])
		{
		if (!(islower(character[i]))) { std::cout << (char)tolower(character[i]); }
		else { std::cout << (char)toupper(character[i]); };
			i++;
		};	
	_getch();
	return 0;
};

int Contributions()
{
	const int arsize = 10;
	std::array<double, arsize> arcotriobutions {};
	double daverage = 0;
	int j = 0;
	std::cout << "Input your contributions (text as input exits):\n";
	for (int i = 0; i < arsize; i++)
		{
		if (!(std::cin >> arcotriobutions[i])) break;
		j = i;
		};
	for (int i = 1; i <= j; i++)
	{
		if (arcotriobutions[i - 1] > 0) { daverage = (daverage + arcotriobutions[i - 1]); };
	};
	daverage /= j;
	std::cout << "Average of contributions: " << daverage;
	for (int i = 1; i < arsize; i++)
	{
		if (arcotriobutions[i] > daverage) { std::cout << "\n" << i+1 << ": " << arcotriobutions[i]; };
	}
	_getch();
	return 0;
};

//not necessarily TODO, but cure for boredom perhaps ...
int Menu()
{
	std::cout << "\t\aThis task was about creating menu ... you are using one all along\n" << "Press any key to continue...\n";
	_getch();
	return 0;
};

//TODO
int Good_Will_Programmers()
{
	std::cout << "\nNothing to see here (YET). Please move along ...\n" << "Press any key to continue ..." << std::endl;
	_getch();
	return 0;
};

int Naturland()
{
	//5k - 0	10k - 10	20k - 15	35k - 20 // 38000 = 0+1000+3000+600
	std::cout << "How much Twarps you earned this year:";
	double dtwarps = 0, dtax = 0;
	std::cin >> dtwarps;
		if (dtwarps >=10000)
		{
			(dtwarps/10000) >= 1 ? dtax += 1000 : dtax += ((int)dtwarps % 10000)*0.10 ;
			if (dtwarps >= 20000)
			{
				(dtwarps / 20000) >= 1 ? dtax += 3000 : dtax += ((int)dtwarps % 20000)*0.15;
				if (dtwarps >= 35000)
				{
					dtax += ((int)dtwarps % 35000)*0.20;
				}
			};
		};
	std::cout << "Tax due this year:  " << dtax << " twarps.\n";
	_getch();
	return 0;
};

int Sponsors()
{
	struct ssponsors
	{
		std::string name;
		double amount;
	};
	ssponsors * sponsortab[10];
	std::cout << "Type amount of sponsors willing to donate\n";
	int namonunt_of_sponsors;
	std::cin >> namonunt_of_sponsors;
	std::cin.ignore(1000, '\n');
	for (int i = 0; i < namonunt_of_sponsors; i++)
	{
		sponsortab[i] = new ssponsors;
		std::cout << "Sponsor " << i+1 << ":\nName: ";
		std::getline(std::cin, (*sponsortab[i]).name);
		std::cout << "Amount:";
		std::cin >> (*sponsortab[i]).amount;
		std::cin.ignore(1000, '\n');
	};
	std::cout << "\nOur generous sposnors:";
	for (int i = 0, namount=0; i < namonunt_of_sponsors; i++)
	{
		if ((*sponsortab[i]).amount>=10000)
		{
			std::cout << "\nName: " << (*sponsortab[i]).name << ", amount: " << (*sponsortab[i]).amount;
			namount++;
		};
		while (i==namonunt_of_sponsors && namount == 0) std::cout << "\nNone";
	};
	std::cout << "\n\nOur sposnors:\n";
	for (int i = 0, namount=0; i < namonunt_of_sponsors; i++)
	{
		if ((*sponsortab[i]).amount < 10000)
		{
			std::cout << "\nName: " << (*sponsortab[i]).name << ", amount: " << (*sponsortab[i]).amount;
			namount++;
		};
		while (i == namonunt_of_sponsors && namount == 0) std::cout << "\nNone";
	};
	_getch();
	return 0;
};

//TODO
int Word_calculator()
{
	char cvovels[] = { 'a','e','i','o','u'};
	char cnumbers[] = { '0','1','2','3','4','5','6','7','8','9' };
	const int arsize = 1000;
	std::cout << "Input text, ' q ' ends sequence:";
	char character[arsize]{"o"};
	int i=2, nvovels=0, nconsonants=0, nother=0;
	while (character[i]= _getch())
	{
		if (isalpha(character[i]) && character[i-1]== ' ')
		{
			if ((character[i] > 'a' && character[i] < 'z') || (character[i] > 'A' && character[i] < 'Z')) nconsonants++; else
			{
				for (int j = 0; j < 4; j++)
				{
					if (character[i] == cvovels[j]) nvovels++;
				};
				for (int j = 0; j < 9; j++)
				{
					if (character[i] == cnumbers[j]) nother++;
				};
			};
		}
		i++;
		if (character[i-1] == ' ' && character[i] == 'q') break;
	}
	std::cout << "In given sentence there are:\n"
		<< nvovels << " words beginning with vovel,\n"
		<< nconsonants << " words beginning with consonants,\n"
		<< nother << " other words";
	_getch();
	return 0;
};

int File_character_counter()
{
	std::ifstream testfile;
	testfile.open("testfile.txt");
	char hlp;
	long long int llinumber_of_characters=0;
	while (!testfile.eof())
	{
		llinumber_of_characters++;
		testfile >> hlp;
		
	}
	std::cout << "There are " << llinumber_of_characters-1 << " of characters in testfile.txt\n"; //program reads NUL as well
	_getch();
	return 0;
};

//TODO
int File_sponsors()
{
	/*std::ofstream fosponsorsfile;
	fosponsorsfile.open("Sponsors_file.txt");
	*/
	struct ssponsors
	{
		std::string name;
		double amount;
	};
	ssponsors * sponsor;
	//std::cout << "Type amount of sponsors willing to donate\n";
	int *namonunt_of_sponsors = new int;
	/*std::cin >> *namonunt_of_sponsors;
	fosponsorsfile << *namonunt_of_sponsors << '\n';
	std::cin.ignore(1000, '\n');
	for (int i = 0; i < *namonunt_of_sponsors; i++)
	{
		sponsor = new ssponsors;
		std::cout << "Sponsor " << i + 1 << ":\nName: ";
		std::getline(std::cin, (*sponsor).name);
		fosponsorsfile << (*sponsor).name << '\n';
		std::cout << "Amount:";
		std::cin >> (*sponsor).amount; 
		fosponsorsfile << (*sponsor).amount << '\n';
		std::cin.ignore(1000, '\n');
		delete sponsor;
	};
	fosponsorsfile.close();
	*/
	std::ifstream fisponsorsfile;
	fisponsorsfile.open("Sponsors_file.txt");
	fisponsorsfile >> *namonunt_of_sponsors;
	std::string pom;
	std::getline(fisponsorsfile, pom);
	std::cout << pom;
	std::cout << "\nOur generous sposnors:";
	for (int i = 0, namount = 0; i < *namonunt_of_sponsors; i++)
	{
		std::getline(fisponsorsfile,(*sponsor).name);
		fisponsorsfile >> (*sponsor).amount;
		if ((*sponsor).amount >= 10000)
		{
			std::cout << "\nName: " << (*sponsor).name << ", amount: " << (*sponsor).amount;
			namount++;
		};
		while (i == *namonunt_of_sponsors && namount == 0) std::cout << "\nNone";
	};
	std::cout << "\n\nOur sposnors:\n";
	fisponsorsfile.seekg(0);
	for (int i = 0, namount = 0; i < *namonunt_of_sponsors; i++)
	{
		fisponsorsfile >> (*sponsor).name;
		fisponsorsfile >> (*sponsor).amount;
		if ((*sponsor).amount < 10000)
		{
			std::cout << "\nName: " << (*sponsor).name << ", amount: " << (*sponsor).amount;
			namount++;
		};
		while (i == *namonunt_of_sponsors && namount == 0) std::cout << "\nNone";
	};
	fisponsorsfile.close();
	_getch();
	return 0;
};


int Chapter_6()
{
	std::string options[]
	{ 
		"Assignment 1:\tlowercase to UPPERCASE",
		"Assignment 2:\tContributions",
		"Assignment 3:\tMenu",
		"Assignment 4:\tOrder of Good Will Programmers",	//TODO
		"Assignment 5:\tNaturland",
		"Assignment 6:\tDonations tracking",
		"Assignment 7:\tCalculating words untill 'q'",
		"Assignment 8:\tAmount of characters in textfile",
		"Assignment 9:\tDonations tracking in file",
		"Back"
	};
	const int amountofoptions = 10;
	int input;
	do
	{
		input = simplemenu(options, amountofoptions);
		switch (input)
		{
		case 0: low_to_UP(); break;
		case 1: Contributions(); break;
		case 2: Menu(); break;
		case 3: Good_Will_Programmers(); break;		//TODO
		case 4:	Naturland(); break;
		case 5: Sponsors(); break;
		case 6: Word_calculator(); break;			//TODO
		case 7: File_character_counter(); break;
		case 8: File_sponsors(); break;				//TODO?
		case 9: {std::cout << "\a\nBack to main menu then!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		};
	} while (input != amountofoptions - 1 && input != 27);
	return input;	//when ESC pressed as input
}

//date of creation: 18.07.2017
//Created by: Marcin Nowak