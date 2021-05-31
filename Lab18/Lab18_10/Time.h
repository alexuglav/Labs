#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Time {
	int mins;
	int secs;

	void correctOverflow();

public:

	void addSeconds(int seconds);

	Time& operator =(const Time&);
	Time& operator ++();
	Time operator ++(int);

	Time operator +(const Time&);

	friend ostream& operator <<(ostream&, const Time&);
	friend istream& operator >>(istream&, Time&);

	friend fstream& operator >>(fstream& fin, Time&);
	friend fstream& operator <<(fstream& fout, const Time&);

	friend bool operator== (Time&, Time&);
	friend bool operator!= (Time&, Time&);
};
