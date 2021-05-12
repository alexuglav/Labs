#include <iostream>
#include "Pair.h"
#include "Complex.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	Pair a;
	cin >> a;
	cout << a;
	Pair b;
	cin >> b;
	cout << b;

	Pair sum = a + b;
	cout << "a + b = " << sum << '\n';

	Complex c;
	cin >> c;
	cout << c;
	Complex d;
	cin >> d;
	cout << d;

	Complex com = c * d;
	cout << "c * d = " << com << '\n';

	Complex sub = c - d;
	cout << "c - d = " << sub << '\n';

	return 0;
}
