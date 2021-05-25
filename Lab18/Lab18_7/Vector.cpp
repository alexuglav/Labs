#ifndef _VECTOR_CPP_
#define _VECTOR_CPP_
#include "Vector.h"

using namespace std;

template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}

template <class T>
Vector<T>::Vector(const Vector& a) {
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}

template <class T>
Vector<T>::~Vector() {
	delete[]data;
	data = 0;
}

template <class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& a) {
	if (this == &a) return *this;
	size = a.size;
	if (data != nullptr) delete data;
	data = new T[size];
	for (int i = 0; i < size; i++) {
		data[i] = a.data[i];
	}
	return *this;
}

template <class T>
T& Vector<T>::operator[](int index) {
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}

template<class T>
Vector<T> Vector<T>::operator * (const int k)
{
	Vector temp(size, data[0]);
	for (int i = 0; i < size; i++)
		temp.data[i] = data[i] * k;
	return temp;
}

template <class T>
int Vector<T>::operator () () {
	return size;
}
#endif
