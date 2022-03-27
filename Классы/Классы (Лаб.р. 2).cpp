#include<iostream>

using namespace std;

class Uravnenie
{
public:
		double A;
		double B;
		double C;

		 Uravnenie()
		{	
			A = 2;
			B = 6;
			C = 1;
			cout << "Конструктор без параметров для обьекта ->" << this << endl;
			cout << endl;
		}


	Uravnenie(double first, double second, double third)
	{		
		A = first;
		B = second;
		C = third;
		cout << "Конструктор с параметрами для обьекта ->" << this << endl;
		cout << endl;
	}
	Uravnenie(const Uravnenie& first)
	{		
		A = first.A;
		B = first.B;
		C = first.C;
		cout << "Вызван конструктор копирования ->" << this << endl;
		cout << endl;
	}
	~Uravnenie()
	{
		cout << "Вызван деструктор для ->" << this << endl;
		cout << endl;
	}
	
	void show()
	{
		cout << "Первый коэффициент: " << A << endl << "Второй коэффициент: " << B << endl << "Третий коэффициент: " << C << endl;
		cout << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	double a, b, c;
	Uravnenie urav1;
	urav1.show();

	cout << "Введите первый коэффициент следующего уравнения: ";
	cin >> a;
	cout << endl;

	cout << "Введите второй коэффициент следующего уравнения: ";
	cin >> b;
	cout << endl;

	cout << "Введите третий коэффициент следующего уравнения: ";
	cin >> c;
	cout << endl;
	if (a || b || c != 0)
	{
		Uravnenie urav2(a, b, c);
		urav2.show();
		Uravnenie urav3(*&urav1);
		urav3.show();
	}
	else
	{
		cout << "Все коэффициент не могут быть равны нулю! ";
		cout << endl << endl;
	}
	return 0;
}
	
