#include <iostream>
#include <map>
#include <algorithm>
#include "Time.h"

using namespace std;

typedef map<int, Time> Tmap;
typedef map<int, Time>::iterator it;
Time s;//добавим глобальную переменную для сравнения с заданным значением

bool greater_s(Time a)//добавим предикат для сравнения заданного значения с объетом типа Time
{
	return (a > s);
}

bool min_pred(pair<int, Time> a, pair<int, Time> b)//предикат для поиска минимального элемента
{
	return (a.second < b.second);
}

bool max_pred(pair<int, Time> a, pair<int, Time> b)//предикат для поиска максимального элемента
{
	return (a.second > b.second);
}

//создать словарь
Tmap make_map(int n)
{
	Tmap m;
	Time t;

	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		m.insert(make_pair(i, t));
	}

	return m;
}

//вывод словаря
void print_map(Tmap m)
{
	it i = m.begin();

	while (i != m.end())
	{
		cout << i->first << ") " << i->second << ", ";
		i++;
	}
	cout << "\n";
}

//добавить минимальный элемент в словарь
void add_min(Tmap& m, int n)
{
	it i = m.begin();
	Tmap buf;
	Time min = min_element(m.begin(), m.end(), min_pred)->second;//поиск мин элемента

	for (int j = 1; j < n; j++)//заполняем буф словарб до ключа n
	{
		buf.insert(make_pair(j, i->second));
		i++;
	}
	buf.insert(make_pair(n, i->second));//добавляем под ключём n новый элемент
	i++;
	int k = n + 1;
	while (i != m.end())//продолжаем заполнять буф словарь
	{
		buf.insert(make_pair(k, i->second));
		k++;
		i++;
	}

	m = buf;
}

//вычисление среднего
Time averege(Tmap m)
{
	it i = m.begin();
	Time sum;
	int size = m.size();

	while (i != m.end())
	{
		sum = sum + i->second;
		i++;
	}

	return (sum / size);
}

//удалить элементы больше среднего
void del_more_aver(Tmap& m)
{
	Tmap buf;
	int size = m.size();
	int k = 1;

	for (int i = 1; i <= size; i++)
		if (!greater_s(m[i]))
		{
			buf.insert(make_pair(k, m[i]));
			k++;
		}

	m = buf;
}

//умножить элемент
void multi(pair<const int, Time>& a)
{
	a.second = a.second * s;
}



int main()
{
	int n;
	cout << "Enter n >> "; cin >> n;

	Tmap m = make_map(n);
	cout << "Your map: "; print_map(m);

	cout << "\nEnter position for add min >> "; cin >> n;
	add_min(m, n);
	cout << "Add min: "; print_map(m);

	s = averege(m);
	cout << "\nAvereage: " << s << "\n";
	del_more_aver(m);
	cout << "Del elements more avereage: "; print_map(m);

	s = max_element(m.begin(), m.end(), max_pred)->second;
	for_each(m.begin(), m.end(), multi);
	cout << "\nMultiple all elements: "; print_map(m);

	return 0;
}