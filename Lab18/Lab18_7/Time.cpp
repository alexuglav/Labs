#include "Time.h"

using namespace std;

istream& operator >>(istream& in, Time& p)
{
	p.min = -1;
	p.sec = -1;
	while (p.min < 0) {
		cout << "Min: ";
		cin >> p.min;
	}
	while (p.sec < 0) {
		cout << "Sec: ";
		cin >> p.sec;
	}
	p.correctOverflow();
	return in;
}

bool operator==(Time& T1, Time& T2)
{
	return (T1.min == T2.min) && (T1.sec == T2.sec);
}

bool operator!=(Time& T1, Time& T2)
{
	return !(T1 == T2);
}

ostream& operator <<(ostream& out, Time& p)
{
	cout << p.min << ":";
	if (p.sec < 10) cout << 0;
	cout << p.sec << '\n';
	return out;
}

Time& Time::operator++()
{
	this->sec++;
	this->correctOverflow();
	return *this;
}

Time Time::operator++(int)
{
	Time temp = *this;
	++temp.sec;
	temp.correctOverflow();
	return temp;
}

Time Time::operator+(const Time& t)
{
	Time n;
	n.min = min + t.min;
	n.sec = sec + t.sec;
	n.correctOverflow();
	return n;
}

Time Time::operator*(const int k)
{
	Time n;
	n.min = min * k;
	n.sec = sec * k;
	n.correctOverflow();
	return n;
}

void Time::correctOverflow()
{
	int mins = 0;
	while (sec >= 60) {
		sec -= 60;
		mins++;
	}
	min += mins;
}

void Time::addSeconds(int seconds)
{
	sec += seconds;
	correctOverflow();
}

Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}
