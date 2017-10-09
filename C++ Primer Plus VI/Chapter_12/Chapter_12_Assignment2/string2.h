#pragma once
#ifndef STRING2_H
#define STRING2_H
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char * str;             // wska�nik ci�gu
	int len;                // d�ugo�� ci�gu
	static int num_strings; // liczba obiekt�w klasy
	static const int CINLIM = 80; // limit d�ugo�ci ci�gu na wej�ciu
public:
	// konstruktory i pozosta�e metody klasy
	String(const char * s);   // konstruktor
	String();                 // konstruktor domy�lny
	String(const String &);   // konstruktor kopiuj�cy
	~String();                // destruktor
	int length() const { return len; }
	// metody przeci��aj�ce operatory
	String & operator=(const String &);
	String & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;
	// funkcje zaprzyja�nione przeci��aj�ce operatory
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream & os, const String & st);
	friend istream & operator>>(istream & is, String & st);
	// metoda statyczna
	static int HowMany();

	friend String operator+(const String &st1, const String &st2);
	void stringlow();
	void stringup();
	unsigned int has(char character);
};
#endif