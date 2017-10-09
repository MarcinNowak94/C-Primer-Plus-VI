#include "../../stdafx.h"
#include "string2.h"

using std::cin;
using std::cout;

// inicjalizacja statycznej sk³adowej klasy
int String::num_strings = 0;

// metoda statyczna
int String::HowMany()
{
	return num_strings;
}

// metody klasy
String::String(const char * s)          // konstruuje obiekt String z ci¹gu C
{
	len = std::strlen(s);               // ustawienie d³ugoœci ci¹gu
	str = new char[len + 1];            // przydzia³ pamiêci
	std::strcpy(str, s);                // inicjalizacja wskaŸnika ci¹gu
	num_strings++;                      // aktualizacja licznika obiektów
}

String::String()                        // konstruktor domyœlny
{
	len = 4;
	str = new char[1];
	str[0] = '\0';                      // domyœlny ci¹g obiektów klasy
	num_strings++;
}

String::String(const String & st)
{
	num_strings++;                      // aktualizacja sk³adowej statycznej
	len = st.len;                       // ta sama d³ugoœæ ci¹gu
	str = new char[len + 1];           // przydzia³ pamiêci
	std::strcpy(str, st.str);           // skopiowanie ci¹gu
}

String::~String()                        // destruktor (niezbêdny)
{
	--num_strings;                       // koniecznie
	delete[] str;                       // koniecznie
}

// metody przeci¹¿aj¹ce operatory
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

// przypisywanie ci¹gu C do obiektu klasy String
String & String::operator=(const char * s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

// pe³ny dostêp do znaków ci¹gu (dla obiektów zwyk³ych)
char & String::operator[](int i)
{
	return str[i];
}

// dostêp (do odczytu) do znaków ci¹gu (dla obiektów const)
const char & String::operator[](int i) const
{
	return str[i];
}

// zaprzyjaŸnione funkcje przeci¹¿aj¹ce operatory
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

// wyprowadzenie ci¹gu na wyjœcie
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

// wczytywanie ci¹gu z wejœcia (uproszczone)
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
in a string to lowercase.(Don’t forget the cctype family of character functions.)
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
