#include "stdafx.h"

#ifndef CLS_H
#define CLS_H

void cls(HANDLE hConsole);

#endif //!CLS_H

#ifndef SIMPLEMENUDISPLAY_H
#define SIMPLEMENUDISPLAY_H

template<class T, class T2, class T3>
int simplemenudisplay(std::vector<bool> menu, T menuoptions[], T2 & amountofoptions, T3 & cursorposition)
{
	char uicursor[2]{ ' ', '*' };
	char input{};
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{

		cls(hStdout);
		std::cout << "------------------------------------------------------------\n";
			for (auto i = 0; i < amountofoptions; i++)
			{
				if (i == amountofoptions - 1)
				{
					std::cout << "------------------------------------------------------------\n"
						<< "[" << uicursor[menu.at(i)] << "] " << menuoptions[i] << "\n";
				}
				else
				{
					std::cout << "[" << uicursor[menu.at(i)] << "] " << menuoptions[i] << "\n";
				}

			}
		input = _getch();
		if (input == '0' || input == '0xE0') { input = _getch(); };		//arrow keys are precieded either by 0 or 0xE0 in input
		switch (input)
		{
		case 72: {if (cursorposition != 0)			//up arrow
		{
			menu[cursorposition - 1] = menu[cursorposition];
			menu[cursorposition] = 0;
			cursorposition -= 1;
			return(simplemenudisplay(menu, menuoptions, amountofoptions, cursorposition));
		}; }; break;
		case 80: {if (cursorposition != amountofoptions - 1)			//down arrow
		{
			menu[cursorposition + 1] = menu[cursorposition];
			menu[cursorposition] = 0;
			cursorposition += 1;
			return(simplemenudisplay(menu, menuoptions, amountofoptions, cursorposition));

		}; }; break;
		case '\r':									//enter
		{
			return cursorposition;
		}; break;
		default: break;
		};
	} while (input != 27);

	return 27;
};

#endif // !SIMPLEMENUDISPLAY_H


#ifndef SIMPLEMENU_H
#define SIMPLEMENU_H

template<class T, class T2>
int simplemenu(T optionstodisplay[], T2 & amountofoptions)
{
	std::vector<bool> menu(1);	//temporary vector remembering position of cursor
	menu.at(0) = 1;					//initializing cursor position at 1st element
	for (auto i = 0; i < amountofoptions; i++)
	{
		menu.push_back(0);
	};
	int cursorpos = 0;
	cursorpos = simplemenudisplay(menu, optionstodisplay, amountofoptions, cursorpos);
	return cursorpos;
};

#endif // !SIMPLEMENU_H


