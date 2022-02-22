
#include <iostream>
using namespace std;
int i, j, n, d;
void SortShell(int A[], int n) //сортировка Шелла
{
	d = n;
	d = d / 2;
	while (d > 0)
	{
		for (i = 0; i < n - d; i++)
		{
			j = i;
			while (j >= 0 && A[j] > A[j + d])
			{
				int count = A[j];
				A[j] = A[j + d];
				A[j + d] = count;
				j--;
			}
		}
		d = d / 2;
	}
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " "; //вывод массива
	}
}
//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Размер массива = "; cin >> n;
	int* A = new int[n]; //объявление динамического массива
	for (i = 0; i < n; i++) //ввод массива
	{
		cout << i + 1 << " элемент = "; cin >> A[i];
	}
	cout << "\nМассив после преобразований : ";
	SortShell(A, n);
	delete[] A; //освобождение памяти
	cout << endl;
	system("pause>>void");
}