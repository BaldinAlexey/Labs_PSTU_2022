// Задание предпологает, что нужно заменить подстроку "strl", но программа работает и с другими подстроками!

#include<iostream>
#include<string>
using namespace std;

int function(string str, string sbstr)
{
	int i;
	int Pos;
	int d[256]{};
	int strl = str.size();
	int allstrl = sbstr.size();

	if (strl != 0 && allstrl != 0)
	{
		for (int i = 0; i < 256; i++)
		{
			d[i] = strl;
		}
		for (int i = strl - 2; i >= 0; i--)
		{
			if (d[int((unsigned char)str[i])] == strl)
			{
				d[int((unsigned char)str[i])] = strl - i - 1;
			}
		}
		Pos = strl - 1;
		while (Pos < allstrl)
		{
			if (str[strl - 1] != sbstr[Pos])
			{
				Pos += d[int((unsigned char)sbstr[Pos])];
			}
			else
			{
				for (i = strl - 1; i >= 0; i--)
				{
					if (str[i] != sbstr[Pos - strl + i + 1])
					{
						Pos += d[int((unsigned char)sbstr[Pos - strl + i + 1])];
						break;
					}
					else if (i == 0)
						return Pos - strl + 1;
				}
			}
		}
	}
	return -1;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	string list;
	int j = 0;
	int Pos;
	int d[256]{};
	string char1;
	string str;
	string allstr;
	cout << "Введите полную строку: ";
	cin >> allstr;
	cout << endl;

	cout << "Введите подстроку, которую заменим: ";
	cin >> str;

	int y = function(str, allstr);

	//cout << "Index: " << y << endl; // индекс первого символа подстроки

	cout << endl;
	for (int i = 0; i < str.size(); i++)
	{
		if ((allstr[y + str.size() + i])!='\0')
		{
			char1 += allstr[y + str.size() + j];	// Сохраняю подряд идущие буквы	после подстроки
			j++;
		}
		else 
		{ 
			cout << "Ошибка! За подстрокой " << str << " " << "пустота, значит следующих символов для замены нет! ";
			cout << endl;
			return -1;
		}
	}

	unsigned int c = 0;
	if (allstr.find(str) == -1)
	{
		cout << "Нет такой подстроки! ";
	}
	else
	{
		cout << "Строка до преобразований: " << allstr << endl;
		cout << endl;

		while (allstr.find(str) != -1)
		{
			allstr.replace(allstr.find(str), str.size(), char1);
			c++;
		}

		cout << "Строка после преобразований: " << allstr << " ";
		cout << endl;
		return 0;
	}
}
