#include <iostream>
#include <list>
#include <algorithm>
#include "Time.h"

using namespace std;

typedef list<Time> Tlist;
Time s;//добавим глобальную переменную для сравнения с заданным значением

//добавим предикат для сравнения заданного значения с объетом типа Time
struct Greater_s
{
	bool operator() (Time t)
	{
		if (t > s) return true;
		else return false;
	}
};

//создание списка
Tlist make_list(int n)
{
	Tlist l;

	for (int i = 0; i < n; i++)
	{
		Time a;
		cin >> a;
		l.push_back(a);
	}

	return l;
}

//печать списка
void print_list(Tlist& l)
{
	Tlist buf;
	int size = l.size();
	for (int i = 0; i < size; i++)
	{
		cout << l.front() << " ";
		buf.push_back(l.front());
		l.pop_front();
	}
	cout << "\n";
	l = buf;
}

//добавление мин элемента на заданную позицию
void add_min(Tlist& l, int n)
{
	if (n > l.size() - 1)
	{
		cout << "Error! Position > size\n";
		return;
	}
	Tlist::iterator i;
	i = min_element(l.begin(), l.end());

	Time min = *i;
	Tlist buf;
	for (int j = 0; j < n - 1; j++)
	{
		buf.push_back(l.front());
		l.pop_front();
	}
	buf.push_back(min);

	int size = l.size();
	for (int i = 0; i < size; i++)
	{
		buf.push_back(l.front());
		l.pop_front();
	}

	l = buf;
}

//вычисление среднего
Time averege(Tlist& l)
{
	Tlist buf;
	int size = l.size();
	Time sum;

	for (int i = 0; i < size; i++)
	{
		sum = sum + l.front();
		buf.push_back(l.front());
		l.pop_front();
	}
	
	l = buf;
	return (sum / size);
}

//умножить элемент
void multi(Time& t)
{
	t = t * s;
}



int main()
{
	int n;
	cout << "Enter n >> "; cin >> n;

	Tlist l;
	l = make_list(n);
	cout << "Your list: ";  print_list(l);

	cout << "\nEnter position for add min >> "; cin >> n;
	add_min(l, n);
	cout << "Add min: ";  print_list(l);

	s = averege(l);
	cout << "\nAverage: " << s << "\n";
	l.erase(remove_if(l.begin(), l.end(), Greater_s()), l.end());
	cout << "Del elements more avereage: ";  print_list(l);

	s = *max_element(l.begin(), l.end());
	for_each(l.begin(), l.end(), multi);
	cout << "\nMultiple all elements: "; print_list(l);

	return 0;
}