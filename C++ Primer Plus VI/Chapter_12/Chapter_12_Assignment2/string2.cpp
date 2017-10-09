#include "../../stdafx.h"
#include "string2.h"

using std::cin;
using std::cout;

// inicjalizacja statycznej sk�adowej klasy
int String::num_strings = 0;

// metoda statyczna
int String::HowMany()
{
	return num_strings;
}

// metody klasy
String::String(const char * s)          // konstruuje obiekt String z ci�gu C
{
	len = std::strlen(s);               // ustawienie d�ugo�ci ci�gu
	str = new char[len + 1];            // przydzia� pami�ci
	std::strcpy(str, s);                // inicjalizacja wska�nika ci�gu
	num_strings++;                      // aktualizacja licznika obiekt�w
}

String::String()                        // konstruktor domy�lny
{
	len = 4;
	str = new char[1];
	str[0] = '\0';                      // domy�lny ci�g obiekt�w klasy
	num_strings++;
}

String::String(const String & st)
{
	num_strings++;                      // aktualizacja sk�adowej statycznej
	len = st.len;                       // ta sama d�ugo�� ci�gu
	str = new char[len + 1];           // przydzia� pami�ci
	std::strcpy(str, st.str);           // skopiowanie ci�gu
}

String::~String()                        // destruktor (niezb�dny)
{
	--num_strings;                       // koniecznie
	delete[] str;                       // koniecznie
}

// metody przeci��aj�ce operatory
// przypisywanie obiektu klasy String do innego obiektu tej klasy
String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// przypisywanie ci�gu C do obiektu klasy String
String & String::operator=(const char * s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

// pe�ny dost�p do znak�w ci�gu (dla obiekt�w zwyk�ych)
char & String::operator[](int i)
{
	return str[i];
}

// dost�p (do odczytu) do znak�w ci�gu (dla obiekt�w const)
const char & String::operator[](int i) const
{
	return str[i];
}

// zaprzyja�nione funkcje przeci��aj�ce operatory
bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

// wyprowadzenie ci�gu na wyj�cie
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

// wczytywanie ci�gu z wej�cia (uproszczone)
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

/*
2. Enhance the String class declaration (that is,upgrade string1.h to string2.h) by
doing the following:
a. Overload the + operator to allow you to join two strings into one.
b. Provide a stringlow() member function that converts all alphabetic characters
in a string to lowercase.(Don�t forget the cctype family of character functions.)
c. Provide a stringup() member function that converts all alphabetic characters
in a string to uppercase.
d. Provide a member function that takes a char argument and returns the number
of times the character appears in the string.
*/

String operator+(const String &st1, const String &st2)
{
	char result[String::CINLIM];
	strcpy(result, st1.str);
	strcat(result, st2.str);
	return(String(result));
};

void String::stringlow()
{
	for (size_t i = 0; i < this->len; i++)
	{
		if (isalpha(this->str[i]))	tolower(this->str[i]);
	}
};

void String::stringup()
{
	for (size_t i = 0; i <= this->len; i++)
	{
		if (isalpha(this->str[i]))	toupper(this->str[i]);
	}
};

unsigned int String::has(char character)
{
	unsigned int occurances = 0;
	for (size_t i = 0; i <= this->len; i++)
	{
		if (this->str[i] == character)	occurances++;
	};
	return occurances;
};
