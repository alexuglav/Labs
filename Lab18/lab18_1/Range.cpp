#include <iostream>
#include "Range.h"

using namespace std;

void Range::Init(double left, double right) {
	if (left > right) {
		int tmp = left;
		left = right;
		right = tmp;
	}
	r_left = left;
	r_right = right;
}
void Range::Read() {
	cout << "Введите левую границу: ";
	cin >> r_left;
	cout << "Введите правую границу: ";
	cin >> r_right;
	if (r_left > r_right) {
		int tmp = r_left;
		r_left = r_right;
		r_right = tmp;
	}
}

void Range::Show() {
	cout << "Левая граница: " << r_left << '\n';
	cout << "Правая граница: " << r_right << '\n';
}

bool Range::rangecheck(double x) {
	return x >= r_left && x <= r_right;
}
