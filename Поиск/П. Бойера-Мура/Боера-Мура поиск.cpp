#include<iostream>
#include<string>
using namespace std;

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
	string str = "strl";
	string allstr = "submstrlondftbv";

	int strl = str.size();
	int allstrl = allstr.size();

	if (strl != 0 && allstrl != 0 )
	{
		for (int i = 0; i < 256; i++)
		{
			d[i] = strl;
		}
		for (i = strl - 2; i >= 0; i--)
		{
			if (d[int((unsigned char)str[i])] == strl)
			{
				d[int((unsigned char)str[i])] = strl - i - 1;
			}
		}
		Pos = strl - 1;
		while (Pos < strl)
		{
			if (str[strl - 1] != allstr[Pos])
			{
				Pos += d[int((unsigned char)allstr[Pos])];
			}
			else
			{
				for (i = strl - 1; i >= 0; i--)
				{
					if (str[i] != allstr[Pos - strl + i + 1])
					{
						Pos += d[int((unsigned char)allstr[Pos - strl + i + 1])];
						break;
					}
				}
			}	
		}	
	}
	
	// cout << "Index: " << Pos - strl + 1 << endl; // индекс первого элемента подстроки(strl)

	char1 = allstr[(Pos - strl + 1) + strl];	// Сохраняю 4 подряд идущие буквы	
	char2 = allstr[(Pos - strl + 1) + strl + 1];
	char3 = allstr[(Pos - strl + 1) + strl + 2];
	char4 = allstr[(Pos - strl + 1) + strl + 3];
	list = char1 + char2 + char3 + char4;   //сохраняю их всех в list, тем самым узнаю подстроку, которую нужно вставить вместо strl

	cout << "Строка до преобразований: " << allstr << endl;
	cout << endl;

	unsigned int c = 0;
		while (allstr.find("strl") != -1)
		{
			allstr.replace(allstr.find("strl"), strl, list);
			c++;
		}

	cout << "Строка после преобразований: " << allstr << " ";
	cout << endl;
	return 0;
}