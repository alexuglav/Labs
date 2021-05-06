#pragma once
#include <string>

using namespace std;

class Number {
	float m_mantissa;
	int m_poryadok;
	string m_number;

	void updateNumber();
public:
	Number();
	Number(float, int);
	Number(const Number&);

	void setMantissa(float);
	void setPoryadok(int);

	void Show();
};
