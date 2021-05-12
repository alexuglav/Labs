#pragma once
#include "Pair.h"

class Complex : Pair {
	int m_real;
	int m_im;

public:
	Complex();
	Complex(int real, int im);

	friend istream& operator >> (istream& in, Complex& p);
	friend ostream& operator << (ostream& out, Complex& p);

	Complex operator *(const Complex&);
	Complex operator -(const Complex&);
};
