#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Human
{
	string FullName;
	string address;
	string passport;
};

int n = 100;
Human* Person = new Human[n];

void CreateFile()
{
    ofstream str;
    str.open("Human.txt");
    string name[] = { "Александр ", "Алексей ", "Анатолий ", "Андрей ", "Антон ", "Аркадий ", "Арсений ", "Артём ", "Артур ", "Борис ", "Вадим ", "Валентин ", "Валерий ", "Василий ", "Виктор ", "Виталий ", "Владимир ", "Владислав ", "Вячеслав ", "Георгий ", "Глеб ", "Григорий ", "Даниил ", "Денис ", "Дмитрий ", "Евгений ", "Егор ", "Иван ", "Игорь ", "Илья ", "Кирилл ", "Константин ", "Лев ", "Леонид ", "Максим ", "Марк ", "Матвей ", "Михаил ", "Никита ", "Николай ", "Олег ", "Павел ", "Пётр ", "Роман ", "Руслан ", "Сергей ", "Степан ", "Тимур ", "Фёдор ", "Юрий ", "Ярослав " };
    string surname[] = { "Алкасиер ", "Булдаков ", "Волков ", "Главатских ", "Глазов ", "Говрилов ", "Долинин ", "Дианов ", "Сабуров ", "Исламов ", "Шамай ", "Филатов ", "Сабуро ", "Сильверхэнд ", "Кореков ", "Брейкин ", "Верещагин ", "Солдатов ", "Путин ", "Кадочников ", "Ферзь ", "Механошин ", "Тулинов ", "Тедеев ", "Колпаков ", "Вохмянин ", "Березовский ", "Серин ", "Пепеляев ", "Тарасов ", "Аркадьев " };
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
        Person[i].address = to_string(a);
        int p = 732461 + i;
        Person[i].passport = to_string(p);
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

bool KMPSearch(string str, string pod)
{
    bool res = 0;
    int d = str.size();
    int e = pod.size();
    int j = 0;
    int k = -1;
    int* pf = new int[1000];
    pf[0] = -1;
    while (j < e - 1) {
        while (k >= 0 && pod[j] != pod[k])
            k = pf[k];
        j++;
        k++;
        if (pod[j] == pod[k]) {
            pf[j] = pf[k];
        }
        else {
            pf[j] = k;
        }
    }
    int i = 0;
    j = 0;
    while (j < e && i < d) {
        while (j >= 0 && str[i] != pod[j]) {
            j = pf[j];
        }
        i++;
        j++;
    }
    delete[] pf;
    if (j == e)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void KMP(string key, int n)
{
    bool l = false;
    bool p = false;
    for (int i = 0; i < n; i++) {
        l = KMPSearch(Person[i].passport, key);
        if (l == true) {
            cout << "Элемент найден под номером: " << i << '\n';
            cout << Person[i].FullName << '\n';
            cout << Person[i].address << '\n';
            cout << Person[i].passport << '\n';
            p = true;
        }
    }
    if (p == false) {
        cout << "Такого элемента нет.";
    }
}

bool BMSearch(string st, string ct)
{
    int stl, ctl;
    stl = st.size();
    ctl = ct.size();
    if (stl != 0 && ctl != 0 && stl >= ctl)
    {
        int i, p;
        int b[256];
        for (i = 0; i < 256; i++)
        {
            b[i] = ctl;
        }
        for (i = ctl - 2; i >= 0; i--)
        {
            if (b[int(unsigned char(ct[i]))] == ctl)
            {
                b[int(unsigned char(ct[i]))] = ctl - i - 1;
            }
        }
        p = ctl - 1;
        while (p < stl)
        {
            if (ct[ctl - 1] != st[p])
            {
                p += b[int((unsigned char)st[p])];
            }
            else
            {
                for (i = ctl - 1; i >= 0; i--)
                {
                    if (ct[i] != st[p - ctl + i + 1])
                    {
                        p += b[int((unsigned char)st[p])];
                        break;
                    }
                    else if (i == 0)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void BM(string key, int n)
{
    bool l = false;
    bool p = false;
    for (int i = 0; i < n; i++) {
        l = BMSearch(Person[i].passport, key);
        if (l == true) {
            cout << "Элемент найден под номером: " << i << '\n';
            cout << Person[i].FullName << '\n';
            cout << Person[i].address << '\n';
            cout << Person[i].passport << '\n';
            p = true;
        }
    }
    if (p == false) {
        cout << "Такого элемента нет.";
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    remove("Human.txt");
    string key;
    CreateFile();
    bool m = true;
    int choice, SearchChoice;

    while (m == true)
    {
        cout << "1: Вывести структуру на экран." << '\n';
        cout << "2: Поиск по паспорту." << '\n';
        cout << "0: Выход." << '\n';
        cin >> choice;
        switch (choice) {
        case(1):
            print();
            break;
        case(2):
            cout << "1: Поиск Бойера-Мура." << '\n';
            cout << "2: Поиск Кнута-Морриса-Пратта." << '\n';
            cout << "0: Вернуться в меню." << '\n';
            cin >> SearchChoice;
            cout << "Введите паспорт: ";
            cin >> key;
            switch (SearchChoice) {
            case(1):
                BM(key, n);
                break;
            case(2):
                KMP(key, n);
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
