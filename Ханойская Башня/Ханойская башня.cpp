#include <iostream>
using namespace std;

int Func(int n, int main, int next, int help)
{
	if (n > 0)
	{
		Func(n - 1, main, help, next);
		cout << main << " Переходит в " << next << endl;
		Func(n - 1, help, next, main);
	}
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество надстроек башни: ";
		cin >> n;
	Func(n, 1, 3, 2);
	return 0;
}