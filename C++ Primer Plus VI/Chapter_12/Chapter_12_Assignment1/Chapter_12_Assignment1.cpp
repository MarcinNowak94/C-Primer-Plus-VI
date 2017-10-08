#include "../../stdafx.h"
#include "../Chapter_12_Functions.h"
#include "Cow.h"

int Chapter_12_Assignment1()
{
	{
		Cow BovineTab[]
		{
			{ "Bernie", "Eating grass", 200 },
			{},
			{ "Fred", "World domination", 350 }
		};
		for (size_t i = 0; i < sizeof(BovineTab) / sizeof(BovineTab[0]); i++)
		{
			std::cout << "Bovine #" << i + 1 << ":\n";
			BovineTab[i].ShowCow();
		};
		std::cout << "\n\nMysterious cow is up to something ...";
		BovineTab[1] = Cow("ShadyCow", "totaly benevolent stuff", 349);
		for (size_t i = 0; i < sizeof(BovineTab) / sizeof(BovineTab[0]); i++)
		{
			std::cout << "Bovine #" << i + 1 << ":\n";
			BovineTab[i].ShowCow();
		};
	};				//block of instructions where all cows meet their demise
	_getch();
	return 0;
};

/*
1. Consider the following class declaration :
	class Cow 
{
	char name[20];
	char * hobby;
	double weight;
	public: Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow c&);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const;  // display all cow data
};
 Provide the implementation for this class and write a short program that uses all the
 member functions.
*/