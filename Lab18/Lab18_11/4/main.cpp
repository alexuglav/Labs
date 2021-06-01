#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

typedef queue<int> ;

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

void PrintQueue(queue<int>& line)
{
	queue<int>temp;
	temp = line;
	while (!temp.empty()) {
		cout << temp.front() << "; ";
		temp.pop();
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		cout << "Введите размер очереди: ";
		int size = Input(true);
		queue<int> line;
		queue<int>temp;
		for (int i = 0; i < size; i++) {
			line.push(rand() % 100);
		}
		PrintQueue(line);
		cout << "\nВведите ключ, по которому надо удалить элемент: ";
		int key = Input(true);
		for (int i = 0; i < size; i++) {
			if (line.front() != key) {
				temp.push(line.front());
			}
			line.pop();
		}
		line = temp;
		PrintQueue(line);
	}
	catch (int)
	{
		cout << "error!";
	}
	return 0;
}
