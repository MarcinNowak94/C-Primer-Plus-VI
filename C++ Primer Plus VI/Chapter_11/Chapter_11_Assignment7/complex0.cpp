#include "../../stdafx.h"
#include "complex0.h"

complex::complex()
{
	//std::cout << "real: ";
	//std::cin >> this->real;
	//std::cout << "imaginary: ";
	//std::cin >> this->imaginary;
};

complex::complex(double A, double B)
{
	this->real = A;
	this->imaginary = B;
};

complex complex::operator+(complex num)
{
	complex result(this->real + num.real, this->imaginary += num.imaginary);
	return result;	
};

complex complex::operator-(complex num)
{
	complex result(this->real - num.real, this->imaginary - num.imaginary);
	return result;
};

complex complex::operator*(complex num)
{
	complex result((this->real*num.real) - (this->imaginary*num.imaginary), (this->real*num.imaginary) + (this->imaginary*num.real));
	return result;
};



complex complex::operator~()
{
	complex result(this->real,this->imaginary);
	result.imaginary= -this->imaginary;
	return result;
};

/*
- Addition : a + c = (A + C, (B + D)i)
- Subtraction : a - c = (A - C, (B - D)i)
- Multiplication : a × c = (A × C - B×D, (A×D + B×C)i)
- Multiplication : (x a real number) : x × c = (x×C, x×Di)
- Conjugation : ~a = (A, -Bi)
*/

complex operator*(double real, complex & num)
{
	complex result(num.real*real, num.imaginary*real);
	return result;
};

complex operator*(complex & num, double real)
{
	complex result(num.real*real, num.imaginary*real);
	return result;
};

std::ostream & operator<< (std::ostream & os, complex & number)
{
	os << '(' << number.real << ', ' << number.imaginary << 'i)';
	return os;
};

std::istream & operator>> (std::istream & is, complex & number)
{
	std::cout << "\nreal: ";
	double input;
	if (is >> input) { std::cout << "r=" << input; number.real = input; }
	else return is;
	std::cout << "imaginary: ";
	if (is >> input) { std::cout << "i=" << input; number.imaginary = input; }
	else return is;
	return is;

};