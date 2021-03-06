// stock20.cpp -- wersja dozbrojona
#include "../../stdafx.h"
#include <iostream>
#include <cstring>
#include "stock20.h"

// konstruktory
Stock::Stock()                   // konstruktor domyślny
{
	char* chrptr = new char[arsize];
	company = chrptr;
    company = "bez nazwy";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
	char* chrptr = new char[arsize];
	company = chrptr;
	for (size_t i = 0; i <= co.length(); i++)
	{
		company[i] = co[i];
	};
    if (n < 0)
    {
        std::cout << "Liczba udziałów nie może być ujemna; "
            << "ustalam liczbę udziałów w " << company << " na 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// destruktor klasy
Stock::~Stock()               // wersja "dyskretna"
{
	delete[] this->company;
}

// pozostałe metody
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Liczba nabywanych udziałów nie może być ujemna. "
            << "Transakcja przerwana.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num > 0)
    {
        cout << "Liczba sprzedawanych udziałów nie może być ujemna. "
            << "Transakcja przerwana.\n";
    }
    else if (num > shares)
    {
        cout << "Nie możesz sprzedać więcej udziałów, niż posiadasz! "
            << "Transakcja przerwana.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    // ustawienie formatu na #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Spółka: " << company
        << "  Liczba udziałów: " << shares << '\n';
    // ustawienie formatu na #.##
    cout.precision(2);
 
    cout << "  Cena udziału: " << share_val << " zł"
        << "  Łączna wartość udziałów: " << total_val << " zł" << '\n';
    // przywrócenie pierwotnego formatu
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

