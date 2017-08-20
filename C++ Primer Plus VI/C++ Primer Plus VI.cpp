// C++ Primer Plus VI.cpp: Okre�la punkt wej�cia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "simplemenu.h"
#include "chapters.h"

int main()
{
	std::string options[]
	{
		"Chapter 1","Chapter 2","Chapter 3",
		"Chapter 4","Chapter 5","Chapter 6",
		"Chapter 7","Chapter 8","Chapter 9",
		"Chapter 10","Chapter 11","Chapter 12",
		"Chapter 13","Chapter 14","Chapter 15",
		"Chapter 16","Chapter 17","Chapter 18",
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
		case 1: {std::cout << "\n\aNo done assignment for Chapter 2. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
		case 2: input=Chapter_3(); break;
		case 3: input=Chapter_4(); break;
		case 4: input=Chapter_5(); break;
		case 5: input=Chapter_6(); break;
		case 6: input=Chapter_7(); break;
		case 7: input=Chapter_8(); break;
		case 8: input=Chapter_9(); break;
		case 9: {std::cout << "\n\aNo done assignment for Chapter 10. Better luck next time though.\n" << "Press any key to continue ...\n"; _getch(); }; break;
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