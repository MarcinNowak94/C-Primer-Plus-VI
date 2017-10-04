#pragma once

class complex
{
	private:
		double real;
		double imaginary;

	public:
		complex();
		~complex() {};
		complex(double A, double B=0);
		complex operator+(complex num);
		complex operator-(complex num);
		complex operator*(complex num);
		complex operator~();

		friend complex operator*(double real, complex & num);
		friend complex operator*(complex & num, double real);
		friend std::ostream & operator<< (std::ostream & os, complex & number);
		friend std::istream & operator>> (std::istream & os, complex & number);
		
};