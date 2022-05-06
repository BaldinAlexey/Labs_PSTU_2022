#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "Time.h"

using namespace std;

typedef list<Time> Tlist;
typedef vector<Time> Tvector;

Time s;//������� ���������� ���������� ��� ��������� � �������� ���������

//������� �������� ��� ��������� ��������� �������� � ������� ���� Time
struct Greater_s
{
	bool operator() (Time t)
	{
		if (t > s) return true;
		else return false;
	}
};

//������� ������
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

//���������� ������ � ������
Tlist copy_vector_to_list(Tvector& v)
{
	Tlist l;
	int size = v.size();

	for (int i = 0; i < size; i++)
		l.push_back(v[i]);

	return l;
}

//���������� ������ � ������
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

//����� �������
void print_vector(Tvector v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

//���������� ��� �������� �� �������� �������
void add_min(Tlist& l, int n)
{
	if (n > l.size() - 1)//���� ������� ������ �������
	{
		cout << "Error! Position > size\n";
		return;
	}
	Tlist::iterator i;
	i = min_element(l.begin(), l.end());//����� ���. ��������

	Time min = *i;
	Tlist buf;
	for (int j = 0; j < n - 1; j++)//�������� ������ � �������� �� n
	{
		buf.push_back(l.front());
		l.pop_front();
	}
	buf.push_back(min);//��������� �� ������� n �������

	int size = l.size();
	for (int i = 0; i < size; i++)//���������� ��������� ����
	{
		buf.push_back(l.front());
		l.pop_front();
	}

	l = buf;
}

//���������� ��������
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

//�������� �������
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