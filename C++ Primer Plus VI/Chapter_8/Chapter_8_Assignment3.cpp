#include "../stdafx.h"
#include "Chapter_8_Functions.h"
#include <string>
#include <cctype>

inline void uppercaseit(std::string& givenstring);


int Chapter_8_Assignment3()
{	
	std::string templatestring = "";
	char end = 'n';
	while ("q"!=templatestring)
	{
		std::cout << "\nInput text (q ends input sequence):";
		std::getline(std::cin, templatestring);
		if (templatestring != "q")
		{
			uppercaseit(templatestring);
			std::cout << templatestring;
		}
	};
	
	std::cout << "\nPress any key to exit ..." << std::endl;
	_getch();
	return 0;
}

inline void uppercaseit(std::string& givenstring)
{
	for (unsigned int i = 0; i < givenstring.size(); i++)
	{
		if (islower(givenstring[i])) 
		{
			givenstring[i] = toupper(givenstring[i]);
		};
	}
	//std::cout << givenstring;
	return;
};

//date of creation: 05.08.2017
//Created by: Marcin Nowak