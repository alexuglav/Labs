#include <iostream>
#include "Time.h"
#include"Vector.h"
#include <map>
using namespace std;
typedef map<int, int>TMap;
typedef TMap::iterator it;
int SafeInput1(bool strict)
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
TMap Make_map(int n)
{
    TMap arr;
    int element;
    for (int i = 0; i < n; i++) {
        element = rand() % 100;
        arr.insert(make_pair(i, element));
    }
    return arr;
}
void PrintMap(TMap arr)
{
    it i;
    int count = 0;
    cout << "==============================" << endl;
    for (i = arr.begin(); i != arr.end();) {
        cout << count << ": " << (*i).second << endl;
        count++;
        i++;
    }
    cout << "==============================" << endl;
}
int SearchingMaxElement(TMap arr)
{
    it i = arr.begin();
    int count = 0, index = 0, max = (*i).second;
    while (i != arr.end()) {
        if (max < (*i).second) {
            max = (*i).second;
            index = count;
        }
        i++;
        count++;
    }
    return index;
}
int srednee(TMap v)
{
    int s = 0;
    for (int i = 0; i < v.size(); i++)
        s += v[i];
    int n = v.size();
    return s / n;
}
void Problem1()
{
    TMap array;
    cout << "Введите размерность ассоциативного контейнера map: ";
    int size = SafeInput1(true);
    array = Make_map(size);
    PrintMap(array);
    int indexOfMaxEl = SearchingMaxElement(array);
    cout << "MAX=" << array[indexOfMaxEl] << endl;
    int tmp = array[indexOfMaxEl];
    for (int i = array.size(); i > 0; i--) {
        int t = array[i - 1];
        array.insert(make_pair(i, t));
        array.erase(i - 1);
    };
    array.erase(0);
    array.insert(make_pair(0, tmp));
    cout << "NEW MAP" << endl;
    PrintMap(array);
    cout << "Введите номер удаляемого элемента: ";
    int key = SafeInput1(true);
    array.erase(key);
    for (int i = key; i < array.size(); i++) {
        int t = array[i + 1];
        array.insert(make_pair(i, t));
        array.erase(i + 1);
    }
    cout << "NEW MAP" << endl;
    PrintMap(array);
    int sr = srednee(array);
    for (int i = 0; i < array.size(); i++) {
        int t = array[i] + sr;
        array.erase(i);
        array.insert(make_pair(i, t));
    };
    PrintMap(array);
}
typedef map<int, Time>TMap2;
typedef TMap2::iterator it2;
TMap2 Make_map2(int size)
{
    Time element;
    TMap2 arr;
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        tmp = rand() % 60;
        element.SetMins(tmp);
        tmp = rand() % 60;
        element.SetSecs(tmp);
        arr.insert(make_pair(i, element));
    }
    return arr;
}
void PrintMap2(TMap2 arr)
{
    it2 i;
    int count = 0;
    cout << "==============================" << endl;
    for (i = arr.begin(); i != arr.end();) {
        cout << count << ": " << (*i).second << endl;
        count++;
        i++;
    }
    cout << "==============================" << endl;
}
TMap2 DeleteKey(TMap2 arr, Time key)
{
    it2 iter = arr.begin();
    int count = 0, index = 0;
    while (iter != arr.end()) {
        if ((*iter).second == key) {
            arr.erase(count);
            return arr;
        }
        iter++;
        count++;
    }
    return arr;
}
void Problem2()
{
    TMap2 array;
    it2 iter;
    cout << "Введите размерность ассоциативного контейнера map: ";
    int size = SafeInput1(true);
    array = Make_map2(size);
    PrintMap2(array);
    cout << "Введите номер удаляемого элемента: ";
    int key = SafeInput1(true);
    array.erase(key);
    for (int i = key; i < array.size(); i++) {
        Time t = array[i + 1];
        array.insert(make_pair(i, t));
        array.erase(i + 1);
    }
    cout << "NEW MAP" << endl;
    PrintMap2(array);
}
void Problem3()
{
    cout << "Введите размерность ассоциативного контейнера map: ";
    int size = SafeInput1(true);
    Vector<int> array(size);
    array.PrintMap();
    int avg = array.FindAverageValue();
    cout << "Среднее арифметическое = " << avg << endl << "NEW MAP" << endl;
    array + avg;
    array.PrintMap();
}
int main()
{
    setlocale(LC_ALL, "ru");
    char vvod = '6';
    while (vvod != '0') {
        cout << "\nКакое задание?" << endl
            << "1) Задание 1;" << endl
            << "2) Задание 2;" << endl
            << "3) Задание 3;" << endl
            << "0) Выход из меню" << "\n\n" << ">";
        cin >> vvod;
        switch (vvod)
        {
        case '1':
        {
            Problem1();
        }
        break;
        case '2':
        {
            Problem2();
        }
        break;
        case '3':
        {
            Problem3();
        }
        break;
        default:
            if (vvod != '0')
                cout << "ERROR!";
            break;
        }
    }
    return 0;
}
