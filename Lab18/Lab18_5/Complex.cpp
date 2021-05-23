#include "Complex.h"

Complex::Complex() {
	real = 0;
	im = 0;
}

Complex::Complex(int a, int b) {
	real = a;
	im = b;
}

Complex Complex::operator*(const Complex& p1)
{
	Complex p;
	p.real = real * p1.real - im * p1.im;
	p.im = real * p1.im + im * p1.real;
	return p;
}

Complex Complex::operator-(const Complex& v1)
{
	Complex v;
	v.real = real - im;
	v.im = v1.real - v1.im;
	return v;
}

void Complex::Show() {
	cout << "(" << real << ", " << im << "i)" << endl;
}
