#include <iostream>
#include "Vector.h"
#include "Vector5.h"
#include <queue>
#include <cstdlib>

using namespace std;

int Input(bool strict)
{
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число!" << endl;
	}
	cin.get();
	return result;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		cout << "Введите размер контейнера: ";
		int size = Input(true);
		Vector5<int> intVec(size);
		intVec.Print();
		int n = intVec.FindAverageValue();
		cout << "Среднее арифметическое: " << n << endl;
		intVec = intVec + n;
		cout << "Изменённый контейнер" << endl;
		intVec.Print();
	}
	catch (int)
	{
		cout << "error!";
	}
	return 0;
}
