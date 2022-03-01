#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<fstream>
#include<string>
#include <Windows.h>
using namespace std;

struct human
{
	string name;
	string sname;
	string lname;
	int year_of_birth;
	int height;
	int weight;

};

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	int t;
	cout << "Введите кол-во человек" << endl;
	cin >> t;
	human* people = new human[t];

	for (int i = 0; i < t; i++)
	{
		cout << "Введите Фамилию: ";
		cin >> people[i].sname;

		cout << "Введите Имя: ";
		cin >> people[i].name;

		cout << "Введите Отчество: ";
		cin >> people[i].lname;

		cout << "Введите Год рождения: ";
		cin >> people[i].year_of_birth;
		while (people[i].year_of_birth < 1950 || people[i].year_of_birth > 2022)
		{
			cout << "Год рождения не по условию, введите еще раз! " << endl;
			cin >> people[i].year_of_birth;
		}

		cout << "Введите Рост: ";
		cin >> people[i].height;
		while (people[i].height < 120 || people[i].height > 200)
		{
			cout << "Рост не по условию, введите еще раз! " << endl;
			cin >> people[i].height;
		}

		cout << "Введите Вес: ";
		cin >> people[i].weight;
		while (people[i].weight < 35 || people[i].weight > 100)
		{
			cout << "Вес не по условию, введите еще раз! " << endl;
			cin >> people[i].weight;
		}
	}

	ofstream humans; // создание файла
	humans.open("human.txt"); // открытие файла

	int k, h, l = 0;
	cout << "Введите рост и вес человека, которого удалят из списка (Рост (от 120-200), (Вес (от 35-100))): ";
	cin >> k >> h;
	while ((k < 120 || k > 200) || (h < 35 || h > 100))
	{
		cout << "Вы ввели недопустимые значения! Введите правильно: ";
		cin >> k >> h;
	}



	if (!humans.is_open())
	{
		cout << "Ошибка открытия файла!";
	}
	else
	{
		for (int i = 0; i < t; i++)
		{
			humans << "Фамилия: " << people[i].sname << " " << "Имя: " << people[i].name << " " << "Отчество: " << people[i].lname << " " << "Год рождения: " << people[i].year_of_birth << " " << "Рост: " << people[i].height << " " << "Вес: " << people[i].weight << endl;
		}
		humans << "\n";

		human* massa_rost = new human[t];
		int j = 0;
		for (int i = 0; i < t; i++)
		{
			if ((people[i].height != k) || (people[i].weight != h))
			{
				massa_rost[j] = people[i];
				j++;
				l++; // размер массива
			}
			else
			{
				continue;
			}
		}


		cout << "Введите фамилию, после которой добавить элемент: ";
		string y;
		int index;
		cin >> y;
		cout << "Введите новый элемент, который будет стоять после введённой фамилии" << endl;

		human element;

		cout << "Введите Фамилию: ";
		cin >> element.sname;

		cout << "Введите Имя: ";
		cin >> element.name;

		cout << "Введите Отчество: ";
		cin >> element.lname;

		cout << "Введите Год рождения: ";
		cin >> element.year_of_birth;
		while (element.year_of_birth < 1950 || element.year_of_birth > 2022)
		{
			cout << "Год рождения не по условию, введите еще раз! " << endl;
			cin >> element.year_of_birth;
		}

		cout << "Введите Рост: ";
		cin >> element.height;
		while (element.height < 120 || element.height > 200)
		{
			cout << "Рост не по условию, введите еще раз! " << endl;
			cin >> element.height;
		}

		cout << "Введите Вес: ";
		cin >> element.weight;
		while (element.weight < 35 || element.weight > 100)
		{
			cout << "Вес не по условию, введите еще раз! " << endl;
			cin >> element.weight;
		}


		int q = l + 1;
		human* finish_mas = new human[q];

		for (int j = 0; j < q; j++)
		{
			if (massa_rost[j].sname == y)
			{
				index = j + 1;

				for (int i = 0; i < index; i++)
				{
					finish_mas[i].sname = massa_rost[i].sname;
					finish_mas[i].name = massa_rost[i].name;
					finish_mas[i].lname = massa_rost[i].lname;
					finish_mas[i].year_of_birth = massa_rost[i].year_of_birth;
					finish_mas[i].height = massa_rost[i].height;
					finish_mas[i].weight = massa_rost[i].weight;
				}

				finish_mas[index].sname = element.sname;
				finish_mas[index].name = element.name;
				finish_mas[index].lname = element.lname;
				finish_mas[index].year_of_birth = element.year_of_birth;
				finish_mas[index].height = element.height;
				finish_mas[index].weight = element.weight;

				for (int i = index + 1; i < q; i++)
				{
					finish_mas[i].sname = massa_rost[i - 1].sname;
					finish_mas[i].name = massa_rost[i - 1].name;
					finish_mas[i].lname = massa_rost[i - 1].lname;
					finish_mas[i].year_of_birth = massa_rost[i - 1].year_of_birth;
					finish_mas[i].height = massa_rost[i - 1].height;
					finish_mas[i].weight = massa_rost[i - 1].weight;
				}
				break;
			}
			else
			{
				finish_mas[j] = massa_rost[j];
			}

		}


		for (int i = 0; i < q; i++)
		{
			humans << "Фамилия: " << finish_mas[i].sname << " " << "Имя: " << finish_mas[i].name << " " << "Отчество: " << finish_mas[i].lname << " " << "Год рождения: " << finish_mas[i].year_of_birth << " " << "Рост: " << finish_mas[i].height << " " << "Вес: " << finish_mas[i].weight << endl;
		}
		humans << "\n";
		humans << "Введенные рост и масса: " << k << " " << h << "\n\n";
		delete[]people;
		delete[]massa_rost;
		delete[]finish_mas;
		humans.close();
	}
}
