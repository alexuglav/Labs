#pragma once
#include "Pair.h"

class Complex : public Pair {
	int real;
	int im;
public:
	Complex();
	Complex(int a, int b);

	Complex operator *(const Complex&);
	Complex operator -(const Complex&);

	void Show();
};
