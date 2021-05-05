#include <iostream>
#include "Range.h"

using namespace std;

Range make_Range(double left, double right) {
	Range result;
	result.Init(left, right);
	return result;
}

int main() {
	setlocale(LC_ALL, "Rus");
	double first, second, x;
	cout << "Введите первую границу: ";
	cin >> first;
	cout << "Введите вторую границу: ";
	cin >> second;
	cout << "Введите X: ";
	cin >> x;
	Range R = make_Range(first, second);
	R.Show();
	bool res = R.rangecheck(x);
	cout << "X ";
	if (res) {
		cout << "принадлежит" << '\n';
	}
	else {
		cout << "не принадлежит" << '\n';
	}
	return 0;
}
