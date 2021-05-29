#pragma once
#include "Object.h"

class Vector {
protected:
	Object** begin;
	int size;
	int current;
public:
	Vector();
	Vector(int count);
	~Vector();

	void Add();
	void Del();
	void Show();
	void HandleEvent(TEvent& event);

	int operator () ();
};
