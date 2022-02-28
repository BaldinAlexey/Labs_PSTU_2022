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
	string FIO;
	int year_of_birth;
	int height;
	int weight;

};


int main()
{
	setlocale(LC_ALL, "Russian");

	ofstream humans; // создание файла
	humans.open("human.txt"); // открытие файла

	int k, h, l = 0;
	cout << "Введите рост и вес человека, которого удалят из списка (Рост (от 120-200), (Вес (от 35-100))): ";
	cin >> k >> h;
	while ((k < 120 || k > 200) && (h < 35 || h > 100))
	{
		cout << "Вы ввели недопустимые значения! Введите правильно: ";
		cin >> k >> h;
	}


	human Baldin = { "Baldin Alexey Igorevich", 2003, 170 , 61 };
	human Panferov = { "Panferov Andrey Petrovich ",2002 ,178 ,67 };
	human Xarlamov = { "Xarlamov Alexander Victorovich ", 1999, 173, 62 };
	human Merzlykov = { "Merzlykov Matvey Alexeevich ", 2004, 171, 60 };

	cout << endl;
	int n = 4;
	human* people = new human[n];
	people[0] = Baldin;
	people[1] = Panferov;
	people[2] = Xarlamov;
	people[3] = Merzlykov;

	if (!humans.is_open())
	{
		cout << "Ошибка открытия файла!";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			humans << "Фамилия Имя Отчество: " << people[i].FIO <<" "<< "Год рождения: " << people[i].year_of_birth << " " << "Рост: " << people[i].height << " " << "Вес: " << people[i].weight << endl;
		}
		humans << "\n";

		human* massa_rost = new human[n];
		int j = 0;
		for (int i = 0; i < n; i++)
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



		string f, y, c, z, w;
		int s = 0;
		while (Baldin.FIO[s] != ' ')
		{

			f += Baldin.FIO[s];
			s += 1;
		}
		int x = 0;
		while (Panferov.FIO[x] != ' ')
		{

			c += Panferov.FIO[x];
			x += 1;
		}
		int p = 0;
		while (Xarlamov.FIO[p] != ' ')
		{

			z += Xarlamov.FIO[p];
			p += 1;
		}
		int a = 0;
		while (Merzlykov.FIO[a] != ' ')
		{

			w += Merzlykov.FIO[a];
			a += 1;
		}
	
		cout << "Введите фамилию, после которой добавить элемент: ";
		cin >> y;
		int q = l + 1;
		human* finish_mas = new human[q];

		if (f == y)
		{
			if (q == 5)
			{
				finish_mas[0] = massa_rost[0];
				finish_mas[1] = { "Perevozov Nikita Anrevich ",2006 ,175 ,64 };
				finish_mas[2] = massa_rost[1];
				finish_mas[3] = massa_rost[2];
				finish_mas[4] = massa_rost[3];
			}
			else 
			{
				finish_mas[0] = massa_rost[0];
				finish_mas[1] = { "Perevozov Nikita Anrevich ",2006 ,175 ,64 };
				finish_mas[2] = massa_rost[1];
				finish_mas[3] = massa_rost[2];
			}
		}

		if (c == y)
		{
			if (q == 5)
			{
				finish_mas[0] = massa_rost[0];
				finish_mas[1] = massa_rost[1];
				finish_mas[2] = { "Perevozov Nikita Anrevich ",2006 ,175 ,64 };
				finish_mas[3] = massa_rost[2];
				finish_mas[4] = massa_rost[3];
			}
			else
			{
				finish_mas[0] = massa_rost[0]; 
				finish_mas[1] = massa_rost[1];
				finish_mas[2] = { "Perevozov Nikita Anrevich ",2006 ,175 ,64 };
				finish_mas[3] = massa_rost[2];
			}
		}

		if (z == y)
		{
			if (q == 5)
			{
				finish_mas[0] = massa_rost[0]; 
				finish_mas[1] = massa_rost[1];
				finish_mas[2] = massa_rost[2];
				finish_mas[3] = { "Perevozov Nikita Anrevich ", 2006, 175, 64 };
				finish_mas[4] = massa_rost[3];
			}
			else
			{
				finish_mas[0] = massa_rost[0]; 
				finish_mas[1] = massa_rost[1];
				finish_mas[2] = { "Perevozov Nikita Anrevich ", 2006, 175, 64 };
				finish_mas[3] = massa_rost[2];
			}
		}

		if (w == y)
		{
			if (q == 5)
			{
				finish_mas[0] = massa_rost[0]; 
				finish_mas[1] = massa_rost[1];
				finish_mas[2] = massa_rost[2];
				finish_mas[3] = massa_rost[3];
				finish_mas[4] = { "Perevozov Nikita Anrevich ", 2006, 175, 64 };
			}
			else
			{
				finish_mas[0] = massa_rost[0];
				finish_mas[1] = massa_rost[1];
				finish_mas[2] = massa_rost[2];
				finish_mas[3] = { "Perevozov Nikita Anrevich ", 2006, 175, 64 };
			}
		}



		for (int i = 0; i < q; i++)
		{
			humans << "Фамилия Имя Отчество: " << finish_mas[i].FIO << " " << "Год рождения: " << finish_mas[i].year_of_birth << " " << "Рост: " << finish_mas[i].height << " " << "Вес: " << finish_mas[i].weight << endl;
		}
		humans << "\n";
		humans << "Введенные рост и масса: " << k << " " << h << "\n\n";
		SetConsoleCP(1251);
		

		humans.close();
	}
}