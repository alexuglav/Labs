#include "number.h"
#include <iostream>
#include <math.h>

using namespace std;

Number::Number()
{
	m_mantissa = NULL;
	m_poryadok = NULL;
	m_number = "";
}

Number::Number(float mantissa, int poryadok) 
{
	m_mantissa = mantissa;
	m_poryadok = poryadok;
	m_number = to_string(m_mantissa * pow(10, m_poryadok));
}

Number::Number(const Number& n)
{
	m_mantissa = n.m_mantissa;
	m_poryadok = n.m_poryadok;
	m_number = n.m_number;
}

void Number::updateNumber()
{
	m_number = to_string(m_mantissa * pow(10, m_poryadok));
}

void Number::setMantissa(float man)
{
	m_mantissa = man;
	updateNumber();
}

void Number::setPoryadok(int por) 
{
	m_poryadok = por;
	updateNumber();
}

void Number::Show() 
{
	cout << "Мантисса: " << m_mantissa << '\n';
	cout << "Порядок: " << m_poryadok << '\n';
	cout << "Строковое представление: " << m_number << '\n';
}
