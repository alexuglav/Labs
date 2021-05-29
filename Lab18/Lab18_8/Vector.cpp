#include <iostream>
#include "Vector.h"
#include "Print.h"
#include "Book.h"

using namespace std;

Vector::Vector() {
	begin = nullptr;
	current = 0;
	size = 0;
}

Vector::Vector(int count) {
	begin = new Object * [count];
	current = 0;
	size = count;
}

Vector::~Vector() {
	if (begin != nullptr) delete[] begin;
	begin = nullptr;
}

void Vector::Add() {
	if (size == 0) {
		cout << "Please make a Vector first" << endl;
		return;
	}
	if (size == current) {
		cout << "Vector is full!" << endl;
		return;
	}
	Object* p;
	cout << "Выберите тип элемента: " << endl;
	cout << "1) Печатное издание (print)" << endl;
	cout << "2) Книга (book)" << endl;
	int choise;
	cin >> choise;
	if (choise == 1) {
		Print* t = new Print;
		t->Input();
		p = t;
	}
	else {
		Book* t = new Book;
		t->Input();
		p = t;
	}

	if (current < size) {
		begin[current] = p;
		current++;
	}
}

void Vector::Show() {
	if (current == 0) {
		cout << "Empty" << endl;
	}
	else {
		Object** p = begin;
		for (int i = 0; i < current; i++) {
			(*p)->Show();
			p++;
			cout << endl;
		}
	}
}

void Vector::Del() {
	if (size == 0) {
		cout << "Please make a Vector first" << endl;
	}
	if (current > 0) current--;
}

int Vector::operator () () {
	return current;
}

void Vector::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		Object** p = begin;
		for (int i = 0; i < current; i++) {
			(*p)->HandleEvent(event);
			p++;
		}
	}
}
