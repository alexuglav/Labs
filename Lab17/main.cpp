#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
struct Human {
	string fio;
	int passport;
	int address;
	void Show()
	{
		cout << "\nФИО: " << fio
			<< "\nПаспорт: " << passport
			<< "\nАдрес: " << address << endl;
	}
	string key;
	void keyforming()
	{
		key = to_string(passport);
	}
	int Hash;
	void hashForming(int M)
	{
		float A = 0.45457;
		float tmp = stoi(key) * A;
		float intpart;
		float floatpart;
		floatpart = modf(tmp, &intpart);
		Hash = trunc((M * floatpart));
	}
};
struct HashTaB {
	vector<Human> human_list;
	string key;
	int Hash;
	void Add_list(Human person)
	{
		human_list.push_back(person);
	}
};
vector<Human> MakeArr(int size)
{
	string names[] = { "Александр ", "Алексей ", "Анатолий ", "Андрей ", "Антон ", "Аркадий ", "Арсений ", "Артём ", "Артур ", "Борис ", "Вадим ", "Валентин ", "Валерий ", "Василий ", "Виктор ", "Виталий ", "Владимир ", "Владислав ", "Вячеслав ", "Георгий ", "Глеб ", "Григорий ", "Даниил ", "Денис ", "Дмитрий ", "Евгений ", "Егор ", "Иван ", "Игорь ", "Илья ", "Кирилл ", "Константин ", "Лев ", "Леонид ", "Максим ", "Марк ", "Матвей ", "Михаил ", "Никита ", "Николай ", "Олег ", "Павел ", "Пётр ", "Роман ", "Руслан ", "Сергей ", "Степан ", "Тимур ", "Фёдор ", "Юрий ", "Ярослав " };
	string secnames[] = { "Алкасиер ", "Булдаков ", "Волков ", "Главатских ", "Глазов ", "Говрилов ", "Долинин ", "Дианов ", "Сабуров ", "Исламов ", "Шамай ", "Филатов ", "Сабуро ", "Сильверхэнд ", "Кореков ", "Брейкин ", "Верещагин ", "Солдатов ", "Путин ", "Кадочников ", "Ферзь ", "Механошин ", "Тулинов ", "Тедеев ", "Колпаков ", "Вохмянин ", "Березовский ", "Серин ", "Пепеляев ", "Тарасов ", "Аркадьев " };
	string thirdnames[] = { "Сергеевич", "Иосифович", "Рюрикович", "Прохорович", "Архипович", "Александрович", "Владимирович", "Богданович", "Никифорович", "Георгиевич" , "Прокофиевич" , "Валериевич" , "Владиславович" , "Данилевич" , "Ульянович" , "Кондратиевич" , "Валериевич" , "Сократович" , "Кондратович" , "Евграфович" , "Алексеевич" , "Кондратович" , "Тихонович" , "Игнатиевич" , "Алексеевич" , "Венедиктович" , "Мартьянович" , "Родионович" , "Тимурович" , "Самуилович" , "Климентович" , "Натанович" , "Леонович" , "Игоревич" , "Захарович" , "Андронович" , "Платонович" , "Несторович" , "Модестович" , "Ерофеевич" , "Адамович" };
	vector <Human> result;
	for (int i = 0; i < size; i++) {
		Human NewPerson;
		NewPerson.fio = names[rand() % 7] + " " + secnames[rand() % 6] + " " + thirdnames[rand() % 5];
		NewPerson.passport = 732461 + i;
		NewPerson.address = rand() % 43233131 + 1;
		result.push_back(NewPerson);
	}
	return result;
}
void InsertionSort(vector<HashTaB>& HashTable)
{
	for (int i = 0; i < HashTable.size(); i++) {
		for (int j = i; j > 0 && HashTable[j - 1].Hash > HashTable[j].Hash; j--) {
			swap(HashTable[j - 1], HashTable[j]);
		}
	}
}
void MakeHashTab(vector<HashTaB>& Table, vector<Human> spisok, int kol)
{
	for (int i = 0; i < spisok.size(); i++) {
		HashTaB tmp;
		spisok[i].keyforming();
		spisok[i].hashForming(spisok.size());
		tmp.Hash = spisok[i].Hash;
		tmp.key = spisok[i].key;
		tmp.Add_list(spisok[i]);
		Table.push_back(tmp);
	}
	InsertionSort(Table);
	for (int i = 0; i < kol - 1;) {
		if (Table[i].Hash == Table[i + 1].Hash) {
			Table[i].human_list.push_back(Table[i + 1].human_list[0]);
			Table.erase(Table.begin() + i + 1);
			kol--;
		}
		else
			i++;
	}
}
string ConvertKey(int passport)
{
	string key1 = to_string(passport);
	return key1;
}
void Show(vector<HashTaB>& Table)
{
	for (int i = 0; i < Table.size(); i++) {
		cout << "\nХеш: " << Table[i].Hash << endl;
		for (int j = 0; j < Table[i].human_list.size(); j++) {
			Table[i].human_list[j].Show();
		}
		if (Table[i].human_list.size() > 1)
			cout << "\nКоличество коллизий: " << Table[i].human_list.size() << endl;
		cout << "=====================================" << endl;
	}
}
Human* Seeking(vector<HashTaB>& Table, string _key)
{
	Human* element = NULL;
	for (int i = 0; i < Table.size(); i++) {
		for (int j = 0; j < Table[i].human_list.size(); j++) {
			if (Table[i].human_list[j].key == _key)
				element = &Table[i].human_list[j];
		}
	}
	return element;
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Ru");
	int kol = -1, keypas;
	while (kol < 1) {
		cout << "Введите количество элементов >";
		cin >> kol;
	}
	vector<Human> spisok = MakeArr(kol);
	vector<HashTaB>Table;
	MakeHashTab(Table, spisok, kol);
	Show(Table);
	string keyToFind;
	cout << "\n\nВведите ключ (паспорт) для поиска через Enter >";
	cin >> keypas;
	cout << "=====================================" << endl;
	keyToFind = ConvertKey(keypas);
	Human* element = Seeking(Table, keyToFind);
	cout << endl;
	if (element == NULL) {
		cout << "Такого элемента нет!!!!!!!!!!!!!!!!!!!";
	}
	else {
		cout << "Такой элемент есть." << endl;
		element->Show();
	}
	cout << "=====================================" << endl;
	return 0;
}
