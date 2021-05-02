#include <iostream>

using namespace std;

void create(int* arr, int* size)
{
	cout << "Введите количество элементов массива ";
	cin >> *size;
	for (int i = 0; i < *size; i++) {
		arr[i] = rand() % 150;
	}
}

void print(int* arr, int size)
{
	cout << "Массив:" << '\n';
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
}

void NS(int* arr, int r, int t)
{
	int p = 1;
	int k = 1;
	int i = 0;
	bool flag = false;
	while (arr[i] <= arr[i + 1] && i < r - 1)
	{
		p++;
		i++;
	}
	if (arr[i] > arr[i + 1] && i < r - 1)
	{
		i++;
		flag = true;
		while (arr[i] <= arr[i + 1] && i < r - 1)
		{
			k++;
			i++;
		}
	}
	int num = i + 1;
	int* a = new int[p];
	int* b = new int[k];
	for (i = 0; i < p; i++)
	{
		a[i] = arr[i];
	}
	int g = 0;
	if (flag == true)
	{
		for (i = p; i < p + k; i++)
		{
			b[g] = arr[i];
			g++;
		}
	}
	int j = 0;
	int l = 0;
	if (flag == true)
	{
		for (i = 0; i < num; i++)
		{
			if ((a[l] < b[j] || j >= k) && l < p)
			{
				arr[i] = a[l];
				l++;
			}
			else if ((a[l] > b[j] || l >= p) && j < k)
			{
				arr[i] = b[j];
				j++;
			}
			else if (a[l] == b[j] && j < k && l < p)
			{
				arr[i] = a[l];
				arr[i + 1] = b[j];
				i++;
				j++;
				l++;
			}
		}
	}
}

void NaturalSort(int* arr, int r, int i)
{
	if (i < r)
	{
		NS(arr, r, i);
		NaturalSort(arr, r, i + 1);
	}
}

void BS(int* arr, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[100];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (arr[start] < arr[final]))) {
			mas[j] = arr[start];
			start++;
		}
		else {
			mas[j] = arr[final];
			final++;
		}
	for (j = first; j <= last; j++)
		arr[j] = mas[j];
	delete[] mas;
}

void BalancedSort(int* arr, int first, int last)
{
	if (first < last) {
		BalancedSort(arr, first, (first + last) / 2);
		BalancedSort(arr, (first + last) / 2 + 1, last);
		BS(arr, first, last);
	}
}

void MS(int* arr, int k)
{
	int b = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
}

void MultiphaseSort(int* arr, int n)
{
	int a = 1, b = 1, k1 = 0, k2 = 0, k3 = 0;
	while (a + b <= n / 2)
	{
		if (a > b)
		{
			b = a + b;
		}
		else
		{
			a = a + b;
		}
		if (n % (a + b) == 0)
		{
			k1 = a;
			k2 = b;
		}
	}
	int* F1 = new int[n];
	int* F2 = new int[n];
	int* F3 = new int[n];
	if ((k1 == 0) && (k2 == 0))
	{
		k1 = 1;
	}
	int s = n / (k1 + k2);
	for (int i = 0; i < k1 * s; i++)
	{
		F1[i] = arr[i];
	}
	MS(F1, k1 * s);
	for (int i = k1 * s; i < (k1 + k2) * s; i++)
	{
		F2[(i - (k1 * s))] = arr[i];
	}
	MS(F2, k2 * s);
	int s1 = s, s2 = s, s3 = s;
	for (int j = 0; j < n; j++)
	{
		if ((k1 * s1 != n) && (k2 * s2 != n) && (k3 * s3 != n))
		{
			if (k1 == 0)
			{
				if (k2 > k3)
				{
					k1 = k3;
					s1 = s2 + s3;
					for (int i = 0; i < k1 * s1; i++)
					{
						if (i < k3 * s3)
						{
							F1[i] = F3[i];
						}
						else
						{
							F1[i] = F2[i - k3 * s3];
						}
					}
					MS(F1, k1 * s1);
					for (int i = 0; i < (k2 * s2 - k3 * s3); i++)
					{
						F2[i] = F2[(i + (k3 * s3))];
					}
					k2 = k2 - k3;
					k3 = 0;
					s3 = 0;
				}
				else
				{
					k1 = k2;
					s1 = s2 + s3;
					for (int i = 0; i < k1 * s1; i++)
					{
						if (i < k2 * s2)
						{
							F1[i] = F2[i];
						}
						else
						{
							F1[i] = F3[i - k2 * s2];
						}
					}
					MS(F1, k1 * s1);
					for (int i = 0; i < (k3 * s3 - k2 * s2); i++)
					{
						F3[i] = F3[(i + (k2 * s2))];
					}
					k3 = k3 - k2;
					k2 = 0;
					s2 = 0;
				}
			}
			else if (k2 == 0)
			{
				if (k1 > k3)
				{
					k2 = k3;
					s2 = s1 + s3;
					for (int i = 0; i < k2 * s2; i++)
					{
						if (i < k3 * s3)
						{
							F2[i] = F3[i];
						}
						else
						{
							F2[i] = F1[i - k3 * s3];
						}
					}
					MS(F2, k2 * s2);
					for (int i = 0; i < (k1 * s1 - k3 * s3); i++)
					{
						F1[i] = F1[(i + (k3 * s3))];
					}
					k1 = k1 - k3;
					k3 = 0;
					s3 = 0;
				}
				else
				{
					k2 = k1;
					s2 = s3 + s1;
					for (int i = 0; i < k2 * s2; i++)
					{
						if (i < k1 * s1)
						{
							F2[i] = F1[i];
						}
						else
						{
							F2[i] = F3[i - k1 * s1];
						}
					}
					MS(F2, k2 * s2);
					for (int i = 0; i < (k3 * s3 - k1 * s1); i++)
					{
						F3[i] = F3[(i + (k1 * s1))];
					}
					k3 = k3 - k1;
					k1 = 0;
					s1 = 0;
				}
			}
			else if (k3 == 0)
			{
				if (k1 > k2)
				{
					k3 = k2;
					s3 = s1 + s2;
					for (int i = 0; i < k3 * s3; i++)
					{
						if (i < k2 * s2)
						{
							F3[i] = F2[i];
						}
						else
						{
							F3[i] = F1[i - k2 * s2];
						}
					}
					MS(F3, k3 * s3);
					for (int i = 0; i < (k1 * s1 - k2 * s2); i++)
					{
						F1[i] = F1[(i + (k2 * s2))];
					}
					k1 = k1 - k2;
					k2 = 0;
					s2 = 0;
				}
				else
				{
					k3 = k1;
					s3 = s1 + s2;
					for (int i = 0; i < k3 * s3; i++)
					{
						if (i < k1 * s1)
						{
							F3[i] = F1[i];
						}
						else
						{
							F3[i] = F2[i - k1 * s1];
						}
					}
					MS(F3, k3 * s3);
					for (int i = 0; i < (k2 * s2 - k1 * s1); i++)
					{
						F2[i] = F2[(i + (k1 * s1))];
					}
					k2 = k2 - k1;
					k1 = 0;
					s1 = 0;
				}
			}
		}
		else {
			if (k1 * s1 == n)
			{
				for (int i = 0; i < n; i++)
				{
					arr[i] = F1[i];
				}
			}
			if (k2 * s2 == n)
			{
				for (int i = 0; i < n; i++)
				{
					arr[i] = F2[i];
				}
			}
			if (k3 * s3 == n)
			{
				for (int i = 0; i < n; i++)
				{
					arr[i] = F3[i];
				}
			}
			j = n;
		}
	}
	delete[] F1;
	delete[] F2;
	delete[] F3;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	cout << "Введите количество элементов массива ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 150;
	}
	int choice;
	bool flag = true;
	while (flag) {
		print(arr, size);
		cout << '\n' << "Выберите действие: " << '\n';
		cout << "1. Сортировка натуральным слиянием" << '\n';
		cout << "2. Сортировка сбалансированным слиянием" << '\n';
		cout << "3. Сортировка многофазным слиянием" << '\n';
		cout << "4. Иницировать массив" << '\n';
		cin >> choice;
		if (choice == 0) {
			flag = false;
		}
		else {
			switch (choice)
			{
			case 1:
				NaturalSort(arr, size, 0);
				break;
			case 2:
				BalancedSort(arr, 0, size - 1);
				break;
			case 3:
				MultiphaseSort(arr, size);
				break;
			case 4:
				create(arr, &size);
				break;
			default:
				cout << "Неизвестная команда.";
				break;
			}
		}
	}
	delete[] arr;
}
