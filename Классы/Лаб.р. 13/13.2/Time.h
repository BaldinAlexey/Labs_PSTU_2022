#pragma once
#include <iostream>

using namespace std;

class Time
{
protected:
	//���������
	int min;
	int sec;
public:
	//������������
	Time(void);//��� ����������
	Time(int, int);//� �����������
	Time(const Time&);//�����������

	//����������
	~Time(void);

	//������������
	void set_min(int);
	void set_sec(int);

	//���������
	int get_min();
	int get_sec();

	//���������� �������� ����������
	Time& operator+ (const Time&);
	Time& operator- (const Time&);
	Time& operator* (const Time&);
	Time& operator/ (int);
	Time& operator= (const Time&);

	//���������� ������� ����������
	Time& operator++ ();
	Time& operator-- ();

	//���������� ���������� ���������
	bool operator<(const Time&);
	bool operator<=(const Time&);
	bool operator>(const Time&);
	bool operator>=(const Time&);
	bool operator==(const Time&);
	bool operator!=(const Time&);

	//���������� ���������� ��� ������ � ������� � �������� ��������
	friend ostream& operator<< (ostream&, const Time&);
	friend istream& operator>> (istream&, Time&);
};

