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
	cout << "Результат вещественных чисел" << " " << function(5.456, 9.235) << endl;
	cout << "Результат комплексных чисел" << " " << function(complex < double > (4, 9) , complex < double > (2, 8)) << endl;
	return 0;
}