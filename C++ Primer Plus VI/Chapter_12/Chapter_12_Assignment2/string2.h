#pragma once
#ifndef STRING2_H
#define STRING2_H
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char * str;             // wskaŸnik ci¹gu
	int len;                // d³ugoœæ ci¹gu
	static int num_strings; // liczba obiektów klasy
	static const int CINLIM = 80; // limit d³ugoœci ci¹gu na wejœciu
public:
	// konstruktory i pozosta³e metody klasy
	String(const char * s);   // konstruktor
	String();                 // konstruktor domyœlny
	String(const String &);   // konstruktor kopiuj¹cy
	~String();                // destruktor
	int length() const { return len; }
	// metody przeci¹¿aj¹ce operatory
	String & operator=(const String &);
	String & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;
	// funkcje zaprzyjaŸnione przeci¹¿aj¹ce operatory
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