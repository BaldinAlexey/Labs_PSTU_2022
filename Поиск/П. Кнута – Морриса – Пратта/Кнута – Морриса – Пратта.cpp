#include<iostream>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	string str = "strl";
	string allstr = "sdjncjnstrldnvjrrstr";

	int i, j, strlen, templlen; int k = 0;

	strlen = str.size(); 
	templlen = allstr.size();
	int* d = new int[templlen];

	i = 0; j = -1;
	d[0] = -1;

	while (i < strlen - 1)
	{
		while (j >= 0 && str[j] != str[i])
		{
			j = d[j];
		}
		++i; ++j;
		if (str[i] == str[j])
		{
			d[i] = d[j];
		}
		else
		{
			d[i] = j;
		}
	}

	i = 0; 
	j = 0;
	for (i = 0, j = 0; (i <= templlen - 1) && (j <= strlen - 1); i++, j++)
	{
		while ((j >= 0) && (str[j] != allstr[i]))
		{
			j = d[j];
		}
	}
	delete[]d;
	int pos = i - j;

	cout << "Индекс первого символа подстроки: " << pos << endl;
	
	if (j == templlen)
	{
		return i - j;
		
	}
	else 
	{
		return -1; 
	}
	return 0;
}