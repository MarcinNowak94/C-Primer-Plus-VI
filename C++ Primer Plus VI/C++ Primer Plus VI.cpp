// C++ Primer Plus VI.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "simplemenu.h"
#include "chapters.h"

int main()
{
	std::string options[]
	{
		"Chapter 1:\tGetting Started with C++ ",
		"Chapter 2:\tSetting Out to C++",
		"Chapter 3:\tDealing with Data",
		"Chapter 4:\tCompound Types",
		"Chapter 5:\tLoops and Relational Expressions",
		"Chapter 6:\tBranching Statements and Logical Operators",
		"Chapter 7:\tFunctions: C++’s Programming Modules",
		"Chapter 8:\tAdventures in Functions",
		"Chapter 9:\tMemory Models and Namespaces",
		"Chapter 10:\tObjects and Classes",
		"Chapter 11:\tWorking with Classes",
		"Chapter 12:\tClasses and Dynamic Memory Allocation",
		"Chapter 13:\tClass Inheritance",
		"Chapter 14:\tReusing Code in C++",
		"Chapter 15:\tFriends, Exceptions, and More",
		"Chapter 16:\tThe string Class and the Standard Template Library",
		"Chapter 17:\tInput, Output, and Files",
		"Chapter 18:\tThe New C++11 Standard",
		"EXIT"
	};
	const int amountofoptions = 19;
	int input=NULL;
	do
	{
		input = simplemenu(options, amountofoptions);
		switch (input)
		{
		case 0: {std::cout << "\n\aChapter 1 had no assignments.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 1: input=Chapter_2(); break;
		case 2: input=Chapter_3(); break;
		case 3: input=Chapter_4(); break;
		case 4: input=Chapter_5(); break;
		case 5: input=Chapter_6(); break;
		case 6: input=Chapter_7(); break;
		case 7: input=Chapter_8(); break;
		case 8: input=Chapter_9(); break;
		case 9: input=Chapter_10(); break;
		case 10: {std::cout << "\n\aNo done assignment for Chapter 11. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 11: {std::cout << "\n\aNo done assignment for Chapter 12. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 12: {std::cout << "\n\aNo done assignment for Chapter 13. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 13: {std::cout << "\n\aNo done assignment for Chapter 14. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 14: {std::cout << "\n\aNo done assignment for Chapter 15. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 15: {std::cout << "\n\aNo done assignment for Chapter 16. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 16: {std::cout << "\n\aNo done assignment for Chapter 17. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 17: {std::cout << "\n\aNo done assignment for Chapter 18. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 18: {std::cout << "\a\nFarewell!" << std::endl; _getch(); }; return EXIT_SUCCESS;
		default:break;
		}
		//std::cout << "(" << input << ")\n";
		//_getch();
	} while (input!=amountofoptions-1 && input!=27);
	
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	std::cout << "\a\t\tFarewell!\n";
	std::cout << "----------------------------------------\n"
		<< "\t  Design and programming\t\t\n"
		<< "\t\t\bMarcin Nowak\n"
		<< "\t\t18-08-2017\n"
		<< "----------------------------------------\n"
		<< "\nPress any key to exit..." << std::endl;
	_getch();
	return EXIT_SUCCESS;
    return 0;
}

//date of creation: 18.08.2017
//Created by: Marcin Nowak