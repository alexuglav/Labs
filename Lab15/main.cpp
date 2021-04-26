#include <iostream>
#include <string>

using namespace std;

struct Item {
    string name;
    int cost;
    void print()
    {
        cout << "Название: " << name << '\n';
        cout << "Цена: " << cost << '\n';
    }
};

void CreateStruct(Item* items, int size)
{
    for (int i = 0; i < size; i++) {
        items[i].name = "Предмет " + to_string(i + 1);
        items[i].cost = rand() % 1545454;
    }
}

void printStr(Item* items, int size)
{
    for (int i = 0; i < size; i++) {
        items[i].print();
    }
}

void HoaraSort(Item* a, int first, int last) {
    int i = first;
    int j = last;
    int pivot = a[(i + j) / 2].cost;
    Item temp;

    while (i <= j)
    {
        while (a[i].cost < pivot)
            i++;
        while (a[j].cost > pivot)
            j--;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (j > first)
        HoaraSort(a, first, j);
    if (i < last)
        HoaraSort(a, i, last);
}

void ShellSort(Item* items, int size) {
    for (int step = size / 2; step > 0; step /= 2) {
        for (int i = step; i < size; i++) {
            Item temp = items[i];

            int j = i;
            while (j >= step && items[j - step].cost > temp.cost) {
                items[j] = items[j - step];
                j -= step;
            }
            items[j] = temp;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int size;
    cout << "Введите количество элементов: ";
    cin >> size;
    Item* items = new Item[size];
    CreateStruct(items, size);
    bool m = true;
    int choice, SortChoice;
    while (m == true)
    {
        cout << "1: Вывести структуру на экран." << '\n';
        cout << "2: Сортировка методом Шелла." << '\n';
        cout << "3: Сортировка методом Хоара." << '\n';
        cout << "0: Выход." << '\n';
        cin >> choice;
        switch (choice) {
        case(1):
            printStr(items, size);
            break;
        case(2):
            ShellSort(items, size);
            break;
        case(3):
            HoaraSort(items, 0, size - 1);
            break;
        case(0):
            m = false;
            break;
        }

    }
    return 0;
}
