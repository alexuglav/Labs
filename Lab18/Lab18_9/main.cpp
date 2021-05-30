#include "Vector.h"
#include "Error.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		int size;
		cout << "Введите размер вектора: "; cin >> size;
		Vector v(size);
		cin >> v;
		cout << "Элементы вектора: " << endl << v;
		int ind;
		cout << "Введите индекс элемента, который хотите вывести: "; cin >> ind;
		int a = v[ind];
		cout << a << endl;
		v--;
		cout << v;
		--v;
		cout << v;
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}
