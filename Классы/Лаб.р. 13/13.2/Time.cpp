#include "Time.h"

//конструкторы
Time::Time(void)//без параметров
{
	min = 0;
	sec = 0;
}
Time::Time(int mn, int sc)//с параметрами
{
	int buf = mn * 60 + sc;//если секунд больше 60, то мы их должны перевести в минуты
	min = buf / 60;
	sec = buf % 60;
}
Time::Time(const Time& t)//копирования
{
	min = t.min;
	sec = t.sec;
}

//деструктор
Time::~Time(void) = default;

//модификаторы
void Time::set_min(int v_min) { min = v_min; }
void Time::set_sec(int v_sec)
{
	int buf = min * 60 + v_sec;//если секунд больше 60, то мы их должны перевести в минуты
	min = buf / 60;
	sec = buf % 60;
}

//селекторы
int Time::get_min() { return min; }
int Time::get_sec() { return sec; }

//перегрузка бинарных операций
Time& Time::operator+ (const Time & t)
{
	int buf = (min * 60) + (t.min * 60) + sec + t.sec;//если секунд больше 60, то мы их должны перевести в минуты
	min = buf / 60;
	sec = buf % 60;
	return *this;
}
Time& Time::operator- (const Time & t)
{
	int buf = (min * 60 + sec) - (t.min * 60 + t.sec);//если секунд больше 60, то мы их должны перевести в минуты
	min = buf / 60;
	sec = buf % 60;
	return *this;
}
Time& Time::operator* (const Time & t)
{
	int buf = (min * 60 + sec) * (t.min * 60 + t.sec);
	min = buf / 60;
	sec = buf % 60;
	return *this;
}
Time& Time::operator/ (int n)
{
	int buf = (min * 60 + sec) / n;
	min = buf / 60;
	sec = buf % 60;
	return *this;
}
Time& Time::operator= (const Time & t)
{
	min = t.min;
	sec = t.sec;
	return *this;
}

//перегрузка унарных операций
Time& Time::operator++ ()
{
	int buf = min * 60 + sec + 1;//если секунд больше 60, то мы их должны перевести в минуты
	min = buf / 60;
	sec = buf % 60;
	return *this;
}
Time& Time::operator-- ()
{
	int buf = min * 60 + sec - 1;//если секунд больше 60, то мы их должны перевести в минуты
	min = buf / 60;
	sec = buf % 60;
	return *this;
}

//перегрузка операторов сравнения
bool Time::operator< (const Time & t)
{
	if (min < t.min || (min == t.min && sec < t.sec)) return true;
	return false;
}
bool Time::operator<= (const Time & t)
{
	if (min <= t.min || (min == t.min && sec <= t.sec)) return true;
	return false;
}
bool Time::operator> (const Time & t)
{
	if (min > t.min || (min == t.min && sec > t.sec)) return true;
	return false;
}
bool Time::operator>=(const Time & t)
{
	if (min >= t.min || (min == t.min && sec >= t.sec)) return true;
	return false;
}
bool Time::operator== (const Time & t)
{
	if (min == t.min && sec == t.sec) return true;
	return false;
}
bool Time::operator!= (const Time & t)
{
	if (min != t.min || sec != t.sec) return true;
	return false;
}

//перегрузка операторов для работы с выходным и входным потоками
ostream& operator<< (ostream & out, const Time & t)
{
	out << t.min << ":" << t.sec;
	return out;
}
istream& operator>> (istream & in, Time & t)
{
	int buf_min;
	int buf_sec;
	cout << "Enter min: "; in >> buf_min;
	cout << "Enter sec: "; in >> buf_sec;
	buf_min = buf_min * 60 + buf_sec;//если секунд больше 60, то мы их должны перевести в минуты
	t.set_min(buf_min / 60);
	t.set_sec(buf_min % 60);
	return in;
}