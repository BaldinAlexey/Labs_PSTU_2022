#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream file1;
	file1.open("file1.txt");
	string text = "";
	int k;
	cout << "Введите кол-во строк(не менее 10)" << endl;
	cin >> k;
	while (k < 10)
	{
		cout << "Введите еще раз! ";
		cin >> k;
	}

	if (!file1.is_open())
	{
		cout << "Ошибка открытия файла!";
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			cout << "введите строку: " << endl;
			getline(cin, text);
			if (text == "")
			{
				cout << "Строка должна быть заполнена хотя бы 1 символом! " << endl;
				cout << "введите строку еще раз: " << endl;
				getline(cin, text);
			}

			file1 << text << endl;

		}
		file1.close();

		ifstream file1;
		ofstream file2;

		file1.open("file1.txt");
		file2.open("file2.txt");

		int h;
		cout << "С какой строки копировать строки? " << endl;
		cin >> h;

		while (h <= 0 || h > k - 4)
		{
			cout << "Введите еще раз! " << endl;
			cin >> h;
		}
		string line = "";
		string line1;
		for (int i = 0; i < h; i++)
		{
			getline(file1, line);
		}
		line1 = line;

		file2 << line1 << '\n';
		for (int i = h + 1; i < h + 5; i++)
		{
			getline(file1, line);
			file2 << line << '\n';
		}
	}
	file1.close();

	char glasn[] = "AaEeIiOoUuYy";
	ifstream file2;

	ifstream for_glasn("file2.txt", ios::in | ios::binary);
	char ch;
	int count = 0;
	while (for_glasn.get(ch))
	{
		if (strchr(glasn, ch))
		{
			count++;
		}
	}
	cout << "Кол-во гласных(английских) букв во втором файле: " << count << endl;

	file2.close();
}