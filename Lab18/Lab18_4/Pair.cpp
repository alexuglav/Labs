#include "Pair.h"

Pair::Pair() {
	m_first = 0;
	m_second = 0;
}

Pair::Pair(int first, int second) {
	m_first = first;
	m_second = second;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "Введите первое число "; 
	cin >> p.m_first;
	cout << "Введите второе число "; 
	cin >> p.m_second;
	return in;
}

ostream& operator<<(ostream& out, Pair& p)
{
	cout << "(" << p.m_first << "; " << p.m_second << ")" << '\n';
	return out;
}

Pair Pair::operator+(const Pair& b)
{
	Pair s;
	s.m_first = m_first + b.m_first;
	s.m_second = m_second + b.m_second;
	return s;
}
