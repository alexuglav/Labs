#include <iostream>
#include "number.h"

using namespace std;

void Show(Number num)
{
	num.Show();
}

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "Конструктор без параметров" << '\n';
	Number n1;
	n1.Show();

	cout << "Конструктор с параметрами" << '\n';
	Number n2(0.123, 2);
	n2.Show();

	cout << "Конструктор копирования" << '\n';
	Number n3 = n2;
	n3.Show();

	float mantissa;
	int poryadok;
	cout << "Введите мантиссу: ";
	cin >> mantissa;
	cout << "Введите порядок: ";
	cin >> poryadok;
	n3.setMantissa(mantissa);
	n3.setPoryadok(poryadok);
	Show(n3);
	return 0;
}
