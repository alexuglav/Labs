#include <iostream>
#include "Dialog.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Список команд:" << endl;
	cout << "m [size] создать группу" << endl;
	cout << "+ добавить элемент в группу" << endl;
	cout << "- удалить элемент из группы" << endl;
	cout << "? вывести информацию об элементах группы" << endl;
	cout << "q выйти из программы" << endl;
	Dialog D;
	D.Execute();
	return 0;
}
