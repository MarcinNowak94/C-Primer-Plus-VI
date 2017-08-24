#include "../stdafx.h"
#include "Chapter_9_Functions.h"
#include <new> //placement new


/*
Maj�c dan� deklaracj� struktury:
struct chaff
{
 char dross[20];
 int slag;
};
napisz program, kt�ry za pomoc� miejscowej wersji operatora new przydzieli w buforze pami��
dla dwuelementowej tablicy struktur. Nast�pnie program powinien przypisa� warto�ci
do sk�adowych struktur(pami�taj �e do kopiowania ci�g�w znak�w nale�y zastosowa� funkcj�
strcpy()) i w prostej p�tli wy�wietli� ich warto�ci. W ramach wariantu pierwszego w roli bufora
mo�na wykorzysta� tablic� statyczn�, jak na listingu 9.10. Drugi watiant powinien przydziela� 
bufor wywo�aniem zwyk�ego operatora new.
*/
const int buffersize = 512;
char buffer[buffersize];

struct chaff
{
	char dross[20];
	int slag;
};

int variant1();
int variant2();


int Chapter_9_Assignment3()
{	
	variant1();
	variant2();
	std::cout << "\nPress any key to continue..." << std::endl;
	_getch();
	return 0;
}

int variant1()
{
	const int arsize = 2;
	char first[] = "first";
	char second[] = "second";
	int someint1 = 1;
	int someint2 = 2;
	chaff* chafftab;
	chafftab = new chaff[arsize];
	std::strcpy(chafftab[0].dross, first);
	chafftab[0].slag = someint1;
	std::strcpy(chafftab[1].dross, second);
	chafftab[1].slag = someint2;
	std::cout << "\nVariant 1:\n"
		<< "Chaff structures :\n\n";
	for (auto i = 0; i < arsize; i++)
	{
		std::cout << "Chafftab[" << i << "] at " << &(chafftab[i]) << ":\n"
			<< "-dross:\t" << chafftab[i].dross << " (at " << &(chafftab[i].dross) << ")\n"
			<< "-slag:\t" << chafftab[i].slag << " (at " << &(chafftab[i].slag) << ")\n\n";
	}
	return 0;
};

int variant2()
{ 
	const int arsize = 2;
	char first[] = "template1"; 
	char second[] = "template2";
	int someint1 = 1;
	int someint2 = 2;
	chaff* chafftab;
	chafftab = new (buffer) chaff[arsize];
	std::strcpy(chafftab[0].dross, first);
	chafftab[0].slag = someint1;
	std::strcpy(chafftab[1].dross, second);
	chafftab[1].slag = someint2;
	std::cout << "\nVariant 2:\n"
		<< "Chaff structures inside buffer (at " << &buffer << "-" <<&buffer+(sizeof(buffer)*buffersize) << "):\n\n";
	for (auto i = 0; i < arsize; i++)
	{
		std::cout << "Chafftab[" << i << "] at " << &(chafftab[i]) << ":\n"
			<< "-dross:\t" << chafftab[i].dross << " (at " << &(chafftab[i].dross) << ")\n"
			<< "-slag:\t" << chafftab[i].slag << " (at " << &(chafftab[i].slag) << ")\n\n";
	}
	return 0;
};

//date of creation: 18.08.2017
//Created by: Marcin Nowak