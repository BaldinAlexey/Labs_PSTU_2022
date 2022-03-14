#include<iostream>
using namespace std;

void inprint(int* arr, int n)
{
	int a = 1;
	int s = 0;
	cout << "Введите НЕотсортированное множество (от 1 до 10, главное чтобы цифры не повторялись): " << endl; // То есть вводите цифры (от 1 до 10) в любом порядке, 
																											 // главное чтобы они не повторялись, т.е. в итоге были все 10 цифр.
	for (int i = 0; i < n; i++)																				 
	{
		cout << "Элемент " << a << " ";
		cin >> arr[i];
		s++;
		cout << endl;
		a++;
		if (arr[i] > 0 && arr[i] <= 10)
		{
			continue;
		}
		else
		{
			cout << "Введите еще раз! ";
			cin >> arr[i];
		}
	}
}

void outprint(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void sort(int* arr, int n)
{
	int tmp;
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 0; j < n - 1 - i; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int search(int* arr, int size, int key)
{
	int left = 0; //левая граница
	int right = size; //правая граница
	int mid = 0; //переменная для записи индекса искомого элемента по формуле
	bool flag = false;
	while ((left <= right) && flag != true)
	{
		mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);//Формула для вычисления mid

		if (arr[mid] < key) //Если искомое значение элемента множества больше значения элемента множества с индексом mid, то алгоритм начинает новый поиск в правой половине множества
		{
			left = mid + 1;
		}
		else if (arr[mid] > key) //Иначе, если искомое значение элемента множества меньше значения элемента множества с индексом mid, то алгоритм начинает новый поиск в левой половине множества
		{
			right = mid + 1;
		}
		else flag = true; //Иначе, то поворот флага
	}
	if (arr[left] == key)
	{
		return left; //Вывод "левую границу"
	}
	else if (arr[right] == key)
	{
		return right; //Вывод "правую границу"
	}
	else
	{
		return -1;//Если не нашёл
	}
}

int main()
{

	setlocale(LC_ALL, "RUS");
	const int n = 10;
	const int k = 5;
	int* arr = new int[n];
	int *masfinal = new int [k];
	inprint(arr, n);
	sort(arr, n);
	cout << "Массив ДО преобразований: ";
	outprint(arr, n);
	cout << endl;
	int chet[k] = { 2,4,6,8,10 };
	int indexN = 0;
	int h = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (arr[i] == chet[j])
			{
				h++;
				int key = arr[i];
				indexN = search(arr, n, key);
				masfinal[j] = arr[indexN];		
			}
		}
	}
	cout << endl;
	cout << "Массив ПОСЛЕ преобразований: ";

	for (int i = 0; i < n - h; i++)
	{
		cout << masfinal[i] << " ";
	}
	cout << endl << endl;

	delete[] arr;
	delete[] masfinal;
	return 0;
}