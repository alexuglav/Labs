#include <iostream>
#include "Time.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	Time a;
	Time b;
	cin >> a;
	cin >> b;
	bool flag = true;
	while (flag) {
		int choice;
		cout << "К какому интервалу добавляем?" << '\n';
		cout << "1. К первому." << '\n';
		cout << "2. Ко второму." << '\n';
		cout << "3. Не добавляем." << '\n';
		cin >> choice;
		switch (choice) 
		{
		case 1:
			cout << "Сколько времени добавляем?" << '\n';
			Time sa;
			cin >> sa;
			a = a + sa;
			break;
		case 2:
			cout << "Сколько времени добавляем?" << '\n';
			Time sb;
			cin >> sb;
			b = b + sb;
			break;
		case 3:
			flag = false;
			break;
		default:
			cout << "Неверный ввод." << '\n';
			break;
		}
	}
	cout << "a = " << a << '\n';
	cout << "b = " << b << '\n';
	if (a == b) cout << "Интервалы равны.";
	if (a != b) cout << "Интервалы не равны.";
	return 0;
}
