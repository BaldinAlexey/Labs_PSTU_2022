#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "Time.h"

using namespace std;

typedef list<Time> Tlist;
typedef vector<Time> Tvector;

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

//создать вектор
Tvector make_vector(int n)
{
	Tvector v;
	Time t;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}

	return v;
}

//копировать вектор в список
Tlist copy_vector_to_list(Tvector& v)
{
	Tlist l;
	int size = v.size();

	for (int i = 0; i < size; i++)
		l.push_back(v[i]);

	return l;
}

//копировать список в вектор
Tvector copy_list_to_vector(Tlist l)
{
	Tvector v;
	int size = l.size();

	for (int i = 0; i < size; i++)
	{
		v.push_back(l.front());
		l.pop_front();
	}

	return v;
}

//вывод вектора
void print_vector(Tvector v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

//добавление мин элемента на заданную позицию
void add_min(Tlist& l, int n)
{
	if (n > l.size() - 1)//если позиция больше размера
	{
		cout << "Error! Position > size\n";
		return;
	}
	Tlist::iterator i;
	i = min_element(l.begin(), l.end());//поиск мин. элемента

	Time min = *i;
	Tlist buf;
	for (int j = 0; j < n - 1; j++)//копируем список в буферный до n
	{
		buf.push_back(l.front());
		l.pop_front();
	}
	buf.push_back(min);//добавляем на позицию n элемент

	int size = l.size();
	for (int i = 0; i < size; i++)//продолжаем заполнять лист
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

	Tvector v = make_vector(n);
	print_vector(v);

	cout << "\nEnter position for add min >> "; cin >> n;
	Tlist temp = copy_vector_to_list(v);
	add_min(temp, n);
	v = copy_list_to_vector(temp);
	cout << "Add min: "; print_vector(v);

	temp = copy_vector_to_list(v);
	s = averege(temp);
	cout << "\nAvereage: " << s << "\n";
	temp.erase(remove_if(temp.begin(), temp.end(), Greater_s()), temp.end());
	v = copy_list_to_vector(temp);
	cout << "Del elements more avereage: ";  print_vector(v);

	temp = copy_vector_to_list(v);
	s = *max_element(temp.begin(), temp.end());
	for_each(temp.begin(), temp.end(), multi);
	v = copy_list_to_vector(temp);
	cout << "\nMultiple all elements: "; print_vector(v);

	return 0;
}