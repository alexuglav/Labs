#include <iostream>
#include <deque>
#include <cstdlib>

using namespace std;

typedef deque<int> Deq;

Deq make_deque(int n)
{
	Deq d;
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 100 - 50;
		d.push_back(a);
	}
	return d;
}

void print_deque(Deq d)
{
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
	cout << endl;
}

int max(Deq d)
{
	int m= d[0];
	for (int i = 0; i < d.size(); i++)
		m = (d[i] > m) ? d[i] : m;
	return m;
}

void add_deque(Deq& d, int el)
{
	d.push_back(el);
}

int srednee(Deq v)
{
	int s = 0;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();//количество элементов в векторе
	return s / n;
}

int main()
{
	try
	{
		deque<int> d;
		int n;
		cout << "N?"; cin >> n;
		d = make_deque(n);
		print_deque(d);
		add_deque(d, max(d));
		print_deque(d);
		cout << "pos? ";
		int p;
		cin >> p;
		d.erase(p - 1 + d.begin());
		print_deque(d);
		int sr = srednee(d);
		for (int i = 0; i < d.size(); i++)
			d[i] += sr;
		print_deque(d);
	}
	catch (int)
	{
		cout << "error!";
	}
	return 0;
}
