#pragma once
#include<iostream>
using namespace std;
template<class Type>
class Vector
{
protected:
	Type* arr;
	int size;
public:
	Vector(int length, Type ptr);
	Vector(const Vector& object);
	~Vector();
	Vector& operator=(const Vector<Type>& other);
	Type& operator[] (int index);
	Vector operator+(const Type k);	
	int operator()();
	void push_back(const Type newElement);
	int get_size();
	friend ostream& operator<< (ostream& out, const Vector<Type>& p)
	{
		for (int i = 0; i < p.size; i++) {
			out << p.arr[i] << " ";
		}
		cout << endl;
		return out;
	}
	friend istream& operator>> (istream& in, Vector<Type>& p)
	{
		for (int i = 0; i < p.size; i++) {
			in >> p.arr[i];
		}
		return in;
	}
};
#include "Vector.cpp"
