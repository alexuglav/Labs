#pragma once
#include <iostream>
using namespace std;

class Time {
	int T_mins;
	int T_secs;

	void correctOverflow();

public:

	void addSeconds(int seconds);

	Time& operator =(const Time&);
	Time& operator ++();
	Time operator ++(int);

	Time operator +(const Time&);

	friend ostream& operator <<(ostream&, Time&);
	friend istream& operator >>(istream&, Time&);
	friend bool operator== (Time &, Time &);
	friend bool operator!= (Time&, Time&);
};
