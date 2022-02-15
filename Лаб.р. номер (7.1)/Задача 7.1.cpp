#include<iostream>
#include<complex>
using namespace std;

complex< double > function(complex< double > a, complex< double > b)
{
	return a * b;
}

double function(double a, double b)
{
	return a * b;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	float i = 7.342, j = 49.476;
	complex < double > x(4.0, 9.0);
	complex < double > y(2.0, 8.0);
	cout << "Результат вещественных чисел"<<" "<< function(i, j) << endl;
	cout << "Результат комплексных чисел" <<" "<< function(x, y) << endl;
}