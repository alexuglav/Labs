#include <iostream>
#include "Vector.h"
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<int> intVec;

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

Vector<int> AddingMaxValue(Vector<int>intVec)
{
	int max = intVec[0];
	for (int i = 0; i < intVec.get_size(); i++) {
		if (max < intVec[i]) {
			max = intVec[i];
		}
	}
	cout << "Max=" << max << endl;
	intVec.push_back(max);
	return intVec;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		cout << "Введите размер контейнера: ";
		int size = Input(true);
		Vector<int> intVec(size, 0);
		cout << intVec;
		intVec = AddingMaxValue(intVec);
		cout << intVec;
	}
	catch (int)
	{
		cout << "error!";
	}
	return 0;
}
