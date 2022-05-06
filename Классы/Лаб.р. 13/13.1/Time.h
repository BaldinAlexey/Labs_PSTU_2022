#pragma once
#include <iostream>

using namespace std;

class Time
{
protected:
	//аттрибуты
	int min;
	int sec;
public:
	//конструкторы
	Time(void);//без параметров
	Time(int, int);//с параметрами
	Time(const Time&);//копирования

	//деструктор
	~Time(void);

	//модификаторы
	void set_min(int);
	void set_sec(int);

	//селекторы
	int get_min();
	int get_sec();

	//перегрузка бинарных операторов
	Time& operator+ (const Time&);
	Time& operator- (const Time&);
	Time& operator* (const Time&);
	Time& operator/ (int);
	Time& operator= (const Time&);

	//перегрузка унарных операторов
	Time& operator++ ();
	Time& operator-- ();

	//перегрузка операторов сравнения
	bool operator<(const Time&);
	bool operator<=(const Time&);
	bool operator>(const Time&);
	bool operator>=(const Time&);
	bool operator==(const Time&);
	bool operator!=(const Time&);

	//перегрузка операторов для работы с входным и выходным потоками
	friend ostream& operator<< (ostream&, const Time&);
	friend istream& operator>> (istream&, Time&);
};

