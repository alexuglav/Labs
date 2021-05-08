#include "Time.h"

using namespace std;

istream& operator >>(istream& in, Time& p)
{
	p.T_mins = -1;
	p.T_secs = -1;
	while (p.T_mins < 0) {
		cout << "Min: ";
		cin >> p.T_mins;
	}
	while (p.T_secs < 0) {
		cout << "Sec: ";
		cin >> p.T_secs;
	}
	p.correctOverflow();
	return in;
}

bool operator==(Time&T1, Time&T2)
{
	return (T1.T_mins == T2.T_mins) && (T1.T_secs == T2.T_secs);
}

bool operator!=(Time& T1, Time& T2)
{
	return !(T1 == T2);
}

ostream& operator <<(ostream& out, Time& p)
{
	cout << p.T_mins << ":";
	if (p.T_secs < 10) cout << 0;
	cout << p.T_secs << '\n';
	return out;
}

Time& Time::operator++()
{
	this->T_secs++;
	this->correctOverflow();
	return *this;
}

Time Time::operator++(int)
{
	Time temp = *this;
	++temp.T_secs;
	temp.correctOverflow();
	return temp;
}

Time Time::operator+(const Time& t)
{
	Time n;
	n.T_mins = T_mins + t.T_mins;
	n.T_secs = T_secs + t.T_secs;
	n.correctOverflow();
	return n;
}

void Time::correctOverflow()
{
	int mins = 0;
	while (T_secs >= 60) {
		T_secs -= 60;
		mins ++;
	}
	T_mins += mins;
}

void Time::addSeconds(int seconds)
{
	T_secs += seconds;
	correctOverflow();
}

Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	T_mins = t.T_mins;
	T_secs = t.T_secs;
	return *this;
}
