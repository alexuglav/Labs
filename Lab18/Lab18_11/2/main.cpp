#include <iostream>
#include "Time.h"
#include <deque>
#include <cstdlib>

using namespace std;

typedef deque<Time> Deq;

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

template <typename T>
void PrintDeque(deque<T> dq)
{
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i] << "; ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		Time obj;
		int tmp = obj.GetMins();
		obj.SetMins(tmp);
		tmp = obj.GetSecs();
		obj.SetSecs(tmp);
		deque<Time>dq;
		cout << "Введите размер двунаправленной очереди: ";
		int size = Input(true);
		for (int i = 0; i < size; i++) {
			dq.push_back(obj);
		}
		PrintDeque(dq);
		cout << "Удаление последнего элемента" << endl;
		dq.pop_back();
		cout << "newSize=" << dq.size() << endl;
		PrintDeque(dq);
	}
	catch (int)
	{
		cout << "error!";
	}
	return 0;
}
