#pragma once
#include <iostream>

using namespace std;

template <class T>
class Vector
{
	int size;
	T* data;
public:
	Vector(int s, T k);
	Vector(const Vector<T>& a);
	~Vector();

	Vector& operator=(const Vector<T>& a);
	T& operator[](int index);
	Vector operator * (int k);
	int operator()();

	friend ostream& operator<< (ostream& out, const Vector<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
			out << a.data[i] << " ";
		return out;
	};

	friend istream& operator>> (istream& in, Vector<T>& a) 
	{
		for (int i = 0; i < a.size; ++i)
			in >> a.data[i];
		return in;
	};
};
#include "Vector.cpp"
