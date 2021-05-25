#include "Vector.h"
#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
	Time t;
	cin >> t;
	cout << t;
	Vector<Time>A(5, t);
	cin >> A;
	cout << A << endl;

	Vector <Time>B(10, t);
	cout << B << endl;
	B = A;
	cout << B << endl;
	cout << A[2] << endl;

	int d = 10;
	cout << "size=" << A() << endl; B = A * d;
	cout << B << endl;

	return 0;
}
