#include "Time.h"

using namespace std;

istream& operator >>(istream& in, Time& p)
{
	p.mins = -1;
	p.secs = -1;
	while (p.mins < 0) {
		cout << "Min: ";
		cin >> p.mins;
	}
	while (p.secs < 0) {
		cout << "Sec: ";
		cin >> p.secs;
	}
	p.correctOverflow();
	return in;
}

bool operator==(Time& T1, Time& T2)
{
	return (T1.mins == T2.mins) && (T1.secs == T2.secs);
}

bool operator!=(Time& T1, Time& T2)
{
	return !(T1 == T2);
}

ostream& operator <<(ostream& out, const Time& p)
{
	cout << p.mins << ":";
	if (p.secs < 10) cout << 0;
	cout << p.secs << '\n';
	return out;
}

Time& Time::operator++()
{
	this->secs++;
	this->correctOverflow();
	return *this;
}

Time Time::operator++(int)
{
	Time temp = *this;
	++temp.secs;
	temp.correctOverflow();
	return temp;
}

Time Time::operator+(const Time& t)
{
	Time n;
	n.mins = mins + t.mins;
	n.secs = secs + t.secs;
	n.correctOverflow();
	return n;
}

void Time::correctOverflow()
{
	int mins = 0;
	while (secs >= 60) {
		secs -= 60;
		mins++;
	}
	mins += mins;
}

void Time::addSeconds(int seconds)
{
	secs += seconds;
	correctOverflow();
}

Time& Time::operator=(const Time& t)
{
	if (&t == this) return *this;
	mins = t.mins;
	secs = t.secs;
	return *this;
}

fstream& operator>>(fstream& fin,Time& p)
{
	fin >> p.mins;
	fin >> p.secs;
	p.correctOverflow();
	return fin;
}

fstream& operator<<(fstream& fout, const Time& p)
{
	fout << p.mins << "\n" << p.secs << "\n";
	return fout;
}
