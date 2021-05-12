#include "Complex.h"

Complex::Complex() {
	m_real = 0;
	m_im = 0;
}

Complex::Complex(int real, int im) {
	m_real = real;
	m_im = im;
}

istream& operator>>(istream& in, Complex& p)
{
	cout << "Введите действительную часть числа ";
	cin >> p.m_real;
	cout << "Введите мнимую часть числа ";
	cin >> p.m_im;
	return in;
}

ostream& operator<<(ostream& out, Complex& p)
{
	cout << "(" << p.m_real << "; " << p.m_im << ")" << '\n';
	return out;
}

Complex Complex::operator*(const Complex& p1)
{
	Complex p;
	p.m_real = m_real * p1.m_real - m_im * p1.m_im;
	p.m_im = m_real * p1.m_im + m_im * p1.m_real;
	return p;
}

Complex Complex::operator-(const Complex& v1) 
{
	Complex v;
	v.m_real = m_real - m_im;
	v.m_im = v1.m_real - v1.m_im;
	return v;
}
