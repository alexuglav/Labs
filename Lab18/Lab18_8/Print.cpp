#include "Print.h"
#include "Event.h"
#include <iostream>

using namespace std;

Print::Print() {
	name = "";
	author = "";
}

Print::Print(string name, string author) {
	name = name;
	author = author;
}

Print::Print(const Print& print) {
	name = print.name;
	author = print.author;
}

Print::~Print() {
}

string Print::getName() {
	return name;
}

string Print::getAuthor() {
	return author;
}

void Print::setName(string name) {
	name = name;
}

void Print::setAuthor(string author) {
	author = author;
}

Print& Print::operator = (const Print& print) {
	if (&print == this) return *this;
	author = print.author;
	name = print.name;
	return *this;
}

void Print::Show() {
	cout << "Book name: " << name << endl;
	cout << "Author: " << author << endl;
}

void Print::Input() {
	cout << "Book name: "; cin >> name;
	cout << "Author: "; cin >> author;
}

void Print::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmName: {
			cout << "Book Name: " << getName() << endl;
			break;
		}
		}
	}
}
