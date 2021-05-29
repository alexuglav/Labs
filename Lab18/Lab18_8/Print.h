#pragma once
#include "Object.h"
#include <string>

using namespace std;

class Print : public Object {
protected:
	string name;
	string author;
public:
	Print();
	Print(string name, string author);
	Print(const Print& print);
	~Print();

	string getName();
	string getAuthor();

	void setName(string name);
	void setAuthor(string author);

	Print& operator = (const Print& print);

	void Show();
	void Input();
	void HandleEvent(TEvent& event);
};
