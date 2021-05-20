#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	
	int size;
	cout << "Введите количество элементов " << '\n';
	cin >> size;
	Vector a(size);
	cin >> a;
	cout << a;

	int k;
	cout << '\n' << "Введите k ";
	cin >> k;
	a = a * k;
	cout << a;

	Iterator l = a.last();
	int b, d;
	cout << '\n' << "Какой элемент с права меняем? ";
	cin >> d;
	cout << '\n' << "Введите новый элемент ";
	cin >> b;
	l - d;
	*l = b;
	cout << a;

	cout << '\n' << "Размер вектора: " << a();
	
	return 0;
}
