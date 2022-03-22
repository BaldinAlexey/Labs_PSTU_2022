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
	return - 1;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	string list;
	int i;
	int Pos;
	int d[256]{};
	string char1;
	string char2;
	string char3;
	string char4;
	string str;
	string allstr;
	cout << "Введите полную строку: ";
	cin >> allstr;
	cout << endl;

	cout << "Введите подстроку, которую заменим: ";
	cin >> str;

	int y = function(str, allstr);

	//cout << "Index: " << y << endl; // индекс первого элемента подстроки(strl)
	cout << endl;

	if (allstr[y + str.size()] && allstr[y + str.size() + 1] && allstr[y + str.size() + 2] && allstr[y + str.size() + 3])
	{
		char1 = allstr[y + str.size()];	// Сохраняю 4 подряд идущие буквы	
		char2 = allstr[y + str.size() + 1];
		char3 = allstr[y + str.size() + 2];
		char4 = allstr[y + str.size() + 3];
	}
	else { cout << " Не найдено! "; }
	list = char1 + char2 + char3 + char4;   //сохраняю их всех в list, тем самым узнаю подстроку, которую нужно вставить вместо strl

	cout << "Строка до преобразований: " << allstr << endl;
	cout << endl;

	unsigned int c = 0;
	while (allstr.find("strl") != -1)
	{
		allstr.replace(allstr.find("strl"), str.size(), list);
		c++;
	}

	cout << "Строка после преобразований: " << allstr << " ";
	cout << endl;
	return 0;
}
