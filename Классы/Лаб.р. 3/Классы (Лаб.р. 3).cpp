#include <iostream>
#include<cmath>

using namespace std;

class Time
{

private:
    int min;
    int sec;

public:
    Time()
    {
        min = 11;
        sec = 30;
    }

    Time(int mn, int sc)
    {
        min = mn;
        sec = sc;
    }

    void Printtime()
    {
        cout << "Введите секунды: ";
        cin >> sec;
        cout << endl;
        while (sec > 60 || sec < 0)
        {
            cout << "Не может быть! ";
            cout << "Введите ещё раз: ";
            cin >> sec;
            cout << endl;
        }
    }

    void showtime()
    {
        cout << min << " : " << sec;
        cout << endl;
    }


    Time operator-(Time) const;
    friend bool operator==(const Time& t2, const Time& t3);
    friend bool operator!=(const Time& t2, const Time& t3);

    ~Time()
    {
        cout << "Вызван деструктор для обьекта " << this << endl;
    }

    void SetMin(int ValueMin)
    {
        min = ValueMin;
    }
    int GetMin()
    {
        return min;
    }
    void Setsec(int Valuesec)
    {
        sec = Valuesec;
    }
    int Getsec()
    {
        return sec;
    }
    void show()
    {
        cout << "Вызваны сеттеры для обьекта " << this << " , " << "Минуты: " << min << " " << "Секунды: " << sec << endl;
        cout << endl;
    }

    void showsec()
    {
        cout << sec;
    }

};


Time Time::operator-(Time  t2) const
{
    int m = min;
    int a = 0, c;
    int s = sec;
    if (t2.sec > sec)
    {
        while (t2.sec > s)
        {
            t2.sec--;
            a++;
            if (t2.sec - s == 0)
            {
                s = 60 - a;
                m--;
            }
        }
    }
    else
    {
        s -= t2.sec;
    }
    return Time(m, s);
}

bool operator==(const Time& t2, const Time& t3)
{
    if (t2.min == t3.min && t2.sec == t3.sec)
        return true;
    else
    {
        return false;
    }

}

bool operator!=(const Time& t2, const Time& t3)
{
    if (t2.min != t3.min || t2.sec != t3.sec)
        return true;
    else
    {
        return false;
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    Time time1, time2, time3, time4;
    time1.Printtime();

    time4.Setsec(40);
    time4.SetMin(12);
    time4.Getsec();
    time4.GetMin();
    time4.show();

    time3 = time2 - time1;

    cout << endl << "Изначальное время: ";
    time2.showtime();
    cout << endl;

    cout << "Введённые секунды: ";
    time1.showsec();
    cout << endl;

    cout << endl;
    cout << "Время после вычитания секунд: ";
    time3.showtime();
    cout << endl;

    time3 = time4 - time1;
    cout << endl;
    cout << "Результат Другого времени, где изначальное время, после изменения сеттером стало (12 : 40), а введённые секунды для вычитания остались прежними: " << endl;
    cout << endl;
    cout << "Результат другого времени: ";
    time3.showtime();
    cout << endl;

    if (time2 == time3)
    {
        cout << "--------------------------------" << endl;
        cout << "Временные промежутки изначального и последнего времени - равны\n";
        cout << "--------------------------------" << endl;
        cout << endl;
    }
    else if (time2 != time3)
    {
        cout << "--------------------------------" << endl;
        cout << "Временные промежутки изначального и последнего времени - не равны\n";
        cout << "--------------------------------" << endl;
        cout << endl;
    }
    return 0;
}
