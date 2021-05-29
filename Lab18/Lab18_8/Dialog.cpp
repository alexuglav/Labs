#include "Dialog.h"
#include "Event.h"
#include <iostream>
#include <string>

using namespace std;

Dialog::Dialog() : Vector() {
	EndState = 0;
}

Dialog::~Dialog() {

}

void Dialog::GetEvent(TEvent& event) {
	string operations = "m+-?q";
	string s;
	getline(cin, s);

	if (operations.find(s[0]) != -1) {
		event.what = evMessage;
		switch (s[0]) {
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case '?': event.command = cmShow; break;
		case 'q': event.command = cmQuit; break;
		}
		if (s.length() > 1) {
			string param = s.substr(1, s.length() - 1);
			event.param = atoi(param.c_str());
		}
	}
	else {
		event.what = evNothing;
	}
}

void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake: { // создание группы
			int s;
			cout << "Введите количество элементов ";
			cin >> s;
			begin = new Object * [s];
			size = s;
			current = 0;
			ClearEvent(event);
			break;
		}
		case cmAdd: { // добавление элемента в группу
			Add();
			ClearEvent(event);
			break;
		}
		case cmDel: { // удаление элемента из группы
			Del();
			ClearEvent(event);
			break;
		}
		case cmShow: { // вывод всех элементов
			Show();
			ClearEvent(event);
			break;
		}
		case cmQuit: { // выход из программы
			EndState = 1;
			ClearEvent(event);
			break;
		}
		default: Vector::HandleEvent(event);
		}
	}
}

void Dialog::Execute() {
	TEvent event;
	do {
		GetEvent(event);
		HandleEvent(event);
		if (event.what != evNothing) {
			ClearEvent(event);
		}
	} while (EndState == 0);
}

void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing;
}
