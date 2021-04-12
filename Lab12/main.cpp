/*
4
ФИО, №паспорта, адрес
№паспорта
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Human
{
	string FullName;
	int address;
	int passport;
};

int n = 100;
Human* Person = new Human[n];

void CreateFile()
{
    ofstream str;
    str.open("Human.txt");
    string name[] = { "Александр ", "Алексей ", "Анатолий ", "Андрей ", "Антон ", "Аркадий ", "Арсений ", "Артём ", "Артур ", "Борис ", "Вадим ", "Валентин ", "Валерий ", "Василий ", "Виктор ", "Виталий ", "Владимир ", "Владислав ", "Вячеслав ", "Георгий ", "Глеб ", "Григорий ", "Даниил ", "Денис ", "Дмитрий ", "Евгений ", "Егор ", "Иван ", "Игорь ", "Илья ", "Кирилл ", "Константин ", "Лев ", "Леонид ", "Максим ", "Марк ", "Матвей ", "Михаил ", "Никита ", "Николай ", "Олег ", "Павел ", "Пётр ", "Роман ", "Руслан ", "Сергей ", "Степан ", "Тимур ", "Фёдор ", "Юрий ", "Ярослав " };
    string surname[] = {"Алкасиер ", "Булдаков ", "Волков ", "Главатских ", "Глазов ", "Говрилов ", "Долинин ", "Дианов ", "Сабуров ", "Исламов ", "Шамай ", "Филатов ", "Сабуро ", "Сильверхэнд ", "Кореков ", "Брейкин ", "Верещагин ", "Солдатов ", "Путин ", "Кадочников ", "Ферзь ", "Механошин ", "Тулинов ", "Тедеев ", "Колпаков ", "Вохмянин ", "Березовский ", "Серин ", "Пепеляев ", "Тарасов ", "Аркадьев " };
    string middlename[] = { "Сергеевич", "Иосифович", "Рюрикович", "Прохорович", "Архипович", "Александрович", "Владимирович", "Богданович", "Никифорович", "Георгиевич" , "Прокофиевич" , "Валериевич" , "Владиславович" , "Данилевич" , "Ульянович" , "Кондратиевич" , "Валериевич" , "Сократович" , "Кондратович" , "Евграфович" , "Алексеевич" , "Кондратович" , "Тихонович" , "Игнатиевич" , "Алексеевич" , "Венедиктович" , "Мартьянович" , "Родионович" , "Тимурович" , "Самуилович" , "Климентович" , "Натанович" , "Леонович" , "Игоревич" , "Захарович" , "Андронович" , "Платонович" , "Несторович" , "Модестович" , "Ерофеевич" , "Адамович" };
    for (int i = 0; i < n; i++)
    {
        int g = rand() % (sizeof(surname) / sizeof(surname[0]));
        Person[i].FullName = surname[g];
        g = rand() % (sizeof(name) / sizeof(name[0]));
        Person[i].FullName += name[g];
        g = rand() % (sizeof(middlename) / sizeof(middlename[0]));
        Person[i].FullName += middlename[g];
        int a = rand() % 43233131 + 1;
        Person[i].address = a;
        int p = 732461 + i;
        Person[i].passport = p;
        str << Person[i].FullName << '\n';
        str << Person[i].passport << '\n';
        str << Person[i].address << '\n';
    }
    str.close();
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "-й человек:" << '\n';
        cout << " " << Person[i].FullName << '\n';
        cout << " " << Person[i].passport << '\n';
        cout << " " << Person[i].address << '\n';
    }
}

void LinSearch(int a)
{
    bool pp = true;
    for (int i = 0; i < n; i++)
    {
        if (Person[i].passport == a)
        {
            cout << "Номер элемента: " << i + 1 << '\n';
            cout << "Человек: " << '\n';
            cout << " " << Person[i].FullName << '\n';
            cout << " " << Person[i].passport << '\n';
            cout << " " << Person[i].address << '\n';
            pp = false;
        }
    }
    if (pp == true)
    {
        cout << "Такого элемента нет." << '\n';
    }
}

void PrmSearch(int key)
{
    bool flag = false;
    int left = 0;
    int right = n;
    int mid;

    while ((left <= right) && (flag != true))
    {
        mid = (left + right) / 2;

        if (Person[mid].passport == key) {
            flag = true;
        }
        if (Person[mid].passport > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    if (flag == false) {
        cout << "Такого элемента в множестве нет.";
    }
    else {
        cout << "Номер элемента: " << mid + 1 << '\n';
        cout << "Человек: " << '\n';
        cout << " " << Person[mid].FullName << '\n';
        cout << " " << Person[mid].passport << '\n';
        cout << " " << Person[mid].address << '\n';
    }
}

void InterSearch(int key)
{
    int mid;
    int left = 0;
    int right = n - 1;
    bool flag = false;

    while (Person[left].passport <= key && Person[right].passport >= key && flag == false)
    {
        mid = left + ((key - Person[left].passport) * (right - left)) / (Person[right].passport - Person[left].passport);
        if (Person[mid].passport < key) {
            left = mid++;
        }
        else {
            if (Person[mid].passport > key) {
                right = mid - 1;
            }
            else {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "Номер элемента: " << mid + 1 << '\n';
        cout << "Человек: " << '\n';
        cout << " " << Person[mid].FullName << '\n';
        cout << " " << Person[mid].passport << '\n';
        cout << " " << Person[mid].address << '\n';
    }
    else {
        cout << "Такого элемента в множестве нет.";
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    remove("Human.txt");
    int a;
    CreateFile();
    bool m = true;
    int choice, SearchChoice;

    while (m == true)
    {
        cout << "1: Записать структуру в файл." << '\n';
        cout << "2: Вывести структуру на экран." << '\n';
        cout << "3: Поиск по паспорту." << '\n';
        cout << "0: Выход." << '\v';
        cin >> choice;
        switch (choice) {
        case(1):
            print();
            break;
        case(2):
            print();
            break;
        case(3):
            cout << "1: Линейный поиск." << '\n';
            cout << "2: Прямой поиск." << '\n';
            cout << "3: Интерполяционный поиск." << '\n';
            cout << "0: Вернуться в меню." << '\v';
            cin >> SearchChoice;
            cout << '\n' << "Введите паспорт: ";
            cin >> a;
            switch (SearchChoice) {
            case(1):
                LinSearch(a);
                break;
            case(2):
                PrmSearch(a);
                break;
            case(3):
                InterSearch(a);
                break;
            case(0):
                break;
            }
            break;
        case(0):
            m = false;
            break;
        }

    }
	return 0;
}
