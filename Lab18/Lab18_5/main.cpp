#include <iostream>
#include "Vector.h"
#include "Complex.h"
#include "Object.h"
#include "Pair.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Pair p1, p2;
	cout << "Введите первую пару" << endl;
	cin >> p1;
	cout << "Введите вторую пару" << endl;
	cin >> p2;
	Pair p3 = p1 + p2;
	cout << endl << "Сумма: " << p3 << endl;
	int a, b;
	cout << "Введите действительное число: "; cin >> a;
	cout << "Введите мнимое число: "; cin >> b;
	Complex c(a, b);
	Object* ptr = &p1;
	ptr->Show();
	ptr = &p2;
	ptr->Show();
	cout << "Комплексное число: ";
	ptr = &c;
	ptr->Show();
	Vector vec(3);
	vec.push(ptr);
	vec.push(&p1);
	cout << "Вектор: " << vec;
	return 0;
}
