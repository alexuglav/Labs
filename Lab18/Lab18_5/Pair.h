#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Pair: public Object {
	int first;
	int second;

public:
	Pair();
	Pair(int f, int s);

	void setFirst(int f);
	void setSecond(int s);

	Pair sum(Pair other);

	void Show();

	Pair operator +(const Pair& t);

	friend istream& operator >> (istream& in, Pair& p);
	friend ostream& operator << (ostream& out, Pair& p);
};
