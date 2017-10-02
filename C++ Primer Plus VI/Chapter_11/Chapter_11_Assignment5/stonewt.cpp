// stonewt.cpp -- implementacje metod klasy Stonewt
#include <iostream>
using std::cout;
#include "stonewt.h"

// konstruuje obiekt Stonewt z wartości typu double
Stonewt::Stonewt(double lbs, state st)
{
    stone = int (lbs) / Lbs_per_stn; // dzielenie całkowite
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
	Mode = st;
}

// konstruuje obiekt Stonewt z liczby kamieni i funtów
Stonewt::Stonewt(int stn, double lbs, state st)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn +lbs;
	Mode = st;
}

Stonewt::Stonewt() // konstruktor domyślny, zeruje obiekt
{
    stone = pounds = pds_left = 0;
	Mode = FPND;
}
Stonewt::~Stonewt() // destruktor
{
}

std::ostream & operator<<(std::ostream & os, Stonewt & obj)
{
	if (obj.Mode==Stonewt::STN)
	{
		return (os << obj.stone << " stones, " << obj.pds_left << " pounds\n");
	};
	if (obj.Mode == Stonewt::IPND)
	{
		return (os << (int)obj.pounds << " pounds\n");
	};
	if (obj.Mode == Stonewt::FPND)
	{
		return (os << obj.pounds << " pounds\n");
	}
	else
	{
		obj.Mode = Stonewt::STN;
		return (os << "wrong state, resetting");
	};
};

Stonewt Stonewt::operator+(Stonewt & obj) const 
{
	Stonewt temp(this->pounds + obj.pounds);
	return (temp);
};					

Stonewt Stonewt::operator-(Stonewt & obj) const
{
	Stonewt temp(this->pounds - obj.pounds);
	return (temp);
};

Stonewt Stonewt::operator*(Stonewt & obj) const
{
	Stonewt temp(this->pounds * obj.pounds);
	return (temp);
};								