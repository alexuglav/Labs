#include "Pair.h"

Pair::Pair() {
	first = 0;
	second = 0;
}

Pair::Pair(int first, int second) {
	first = first;
	second = second;
}

void Pair::setFirst(int f) {
	first = f;
}

void Pair::setSecond(int s) {
	second = s;
}

Pair Pair::sum(Pair b) {
	Pair result;
	result.setFirst(first + second);
	result.setSecond(b.first + b.second);
	return result;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "Введите первое число: "; cin >> p.first;
	cout << "Введите второе число: "; cin >> p.second;
	return in;
}

ostream& operator<<(ostream& out, Pair& p)
{
	cout << "(" << p.first << "; " << p.second << ")" << endl;
	return out;
}

void Pair::Show() {
	cout << "(" << first << "; " << second << ")" << endl;
}

Pair Pair::operator +(const Pair& t)
{
	Pair r;
	r.first = first + t.second;
	r.second = second + t.first;
	return r;
}
