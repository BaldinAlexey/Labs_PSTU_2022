#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int k = 0, k1 = 0, j;
	const int size = 11;
	int mas[100]{};
	int mas1[100]{};
	int mas2[100]{};
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 11;
	}

	for (int i = 0; i < size; i++)
	{
		cout << mas[i]<<" ";
	}
	cout << endl;





	for (int i = 0; i < size; i++) 
	{
		if (mas[i] % 7==0 || mas[i]==0)
		{
			k++;
		}
	}

	j = 0;
	for (int i = 0; i < size; i++)
	{
		if ((mas[i] % 7 != 0) || (mas[i]==0))
		{
			mas1[j] = mas[i];
			j++;
		}
	}




	for (int i = 0; i < size - k; i++)
	{
		if (mas1[i] % 2 != 0)
		{
			k1++;
		}
	}

	j = 0;
	for (int i = 0; i < size - k + k1; i++)
	{
		if (mas1[i] % 2 != 0)
		{ 
			mas2[j] = mas1[i];
			mas2[j + 1] = 0;
			j+=2;
		}
		else
		{
			mas2[j] = mas1[i];
			j++;
		}
	}


	for (int j = 0; j <= size - k + k1; j++)
	{
		cout << mas2[j] << " ";
	}

	return 0;
}