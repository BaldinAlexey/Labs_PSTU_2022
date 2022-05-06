#include "Time.h"

//������������
Time::Time(void)//��� ����������
{
	min = 0;
	sec = 0;
}
Time::Time(int mn, int sc)//� �����������
{
	int buf = mn * 60 + sc;//���� ������ ������ 60, �� �� �� ������ ��������� � ������
	min = buf / 60;
	sec = buf % 60;
}
Time::Time(const Time& t)//�����������
{
	min = t.min;
	sec = t.sec;
}

//����������
Time::~Time(void) = default;

//������������
void Time::set_min(int v_min) { min = v_min; }
void Time::set_sec(int v_sec)
{
	int buf = min * 60 + v_sec;//���� ������ ������ 60, �� �� �� ������ ��������� � ������
	min = buf / 60;
	sec = buf % 60;
}

//���������
int Time::get_min() { return min; }
int Time::get_sec() { return sec; }

//���������� �������� ��������
Time& Time::operator+ (const Time& t)
{
	int buf = (min * 60) + (t.min * 60) + sec + t.sec;//���� ������ ������ 60, �� �� �� ������ ��������� � ������
	min = buf / 60;
	sec = buf % 60;
	return *this;
}
Time& Time::operator- (const Time& t)
{
	int buf = (min * 60 + sec) - (t.min * 60 + t.sec);//���� ������ ������ 60, �� �� �� ������ ��������� � ������
	min = buf / 60;
	sec = buf % 60;
	return *this;
}
Time& Time::operator* (const Time& t)
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
Time& Time::operator= (const Time& t)
{
	min = t.min;
	sec = t.sec;
	return *this;
}

//���������� ������� ��������
Time& Time::operator++ ()
{
	int buf = min * 60 + sec + 1;//���� ������ ������ 60, �� �� �� ������ ��������� � ������
	min = buf / 60;
	sec = buf % 60;
	return *this;
}
Time& Time::operator-- ()
{
	int buf = min * 60 + sec - 1;//���� ������ ������ 60, �� �� �� ������ ��������� � ������
	min = buf / 60;
	sec = buf % 60;
	return *this;
}

//���������� ���������� ���������
bool Time::operator< (const Time& t)
{
	if (min < t.min || (min == t.min && sec < t.sec)) return true;
	return false;
}
bool Time::operator<= (const Time& t)
{
	if (min <= t.min || (min == t.min && sec <= t.sec)) return true;
	return false;
}
bool Time::operator> (const Time& t)
{
	if (min > t.min || (min == t.min && sec > t.sec)) return true;
	return false;
}
bool Time::operator>=(const Time& t)
{
	if (min >= t.min || (min == t.min && sec >= t.sec)) return true;
	return false;
}
bool Time::operator== (const Time& t)
{
	if (min == t.min && sec == t.sec) return true;
	return false;
}
bool Time::operator!= (const Time& t)
{
	if (min != t.min || sec != t.sec) return true;
	return false;
}

//���������� ���������� ��� ������ � �������� � ������� ��������
ostream& operator<< (ostream& out, const Time& t)
{
	out << t.min << ":" << t.sec;
	return out;
}
istream& operator>> (istream& in, Time& t)
{
	int buf_min;
	int buf_sec;
	cout << "Enter min: "; in >> buf_min;
	cout << "Enter sec: "; in >> buf_sec;
	buf_min = buf_min * 60 + buf_sec;//���� ������ ������ 60, �� �� �� ������ ��������� � ������
	t.set_min(buf_min / 60);
	t.set_sec(buf_min % 60);
	return in;
}