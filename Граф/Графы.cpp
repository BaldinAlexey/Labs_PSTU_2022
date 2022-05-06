#include <iostream>

int SIZE = 6;
const int n = 10000; // заглушка для прохода в цикл 

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int a[6][6] = // матрица связей
		
	{ /*/1./*/{0,0,5,16,0,0},
	  /*/2./*/{0,0,33,0,9,20},
	  /*/3./*/{5,33,0,0,7,0},
	  /*/4./*/{16,0,0,0,10,14},
	  /*/5./*/{0,9,7,10,0,0},
	  /*/6./*/{0,20,0,14,0,0}
	}; 

	int min_d[6]; // минимальное расстояние
	int count[6]; // посещенные вершины
	int temp, minindex, min;
	int begin_index = 0;

	cout << endl << "Матрица связей: " << endl << endl;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (a[i][j] > 9)
			{
				cout <<" " << a[i][j];
			}
			else { cout << " " << a[i][j]<<" "; }
		}
		cout << endl;
	}

	//Инициализация вершин и расстояний
	for (int i = 0; i < SIZE; i++)
	{
		min_d[i] = n;
		count[i] = 1;
	}
	min_d[begin_index] = 0;
	
	do {
		minindex = n;
		min = n;
		for (int i = 0; i < SIZE; i++)
		{ // Если вершину ещё не обошли и вес меньше min
			if ((count[i] == 1) && (min_d[i] < min))
			{ 
				min = min_d[i];
				minindex = i;
			}
		}
	
		if (minindex != n)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp = min + a[minindex][i];
					if (temp < min_d[i])
					{
						min_d[i] = temp;
					}
				}
			}
			count[minindex] = 0;
		}
	} 
	while (minindex < n);

	cout << endl << "Кратчайшие расстояния до вершин: " << endl << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "До " << (i+1) << " вершины: ";
		cout << " " << min_d[i] << endl << endl;
	}

	return 0;
}