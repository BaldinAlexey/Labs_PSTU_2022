#include <iostream>
#include <sstream>


using namespace std;

class Time
{
    int first;
    int second;

public:

    void Pole(int first, int second)
    {
        this->first = first;
        this->second = second;
    }


    void minutes(int first, int second)
    {
        int h, m;
        h = first * 60;
        m = second;
        cout << "Ваше время в минутах: ";
        cout << h + m;
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
    Time time;
    int hour, minute;
    cout << "Введите время: " << endl;
    cout << endl;

    cout << "Часы: ";
    cin >> hour;

    cout << endl;

    cout << "Минуты: ";
    cin >> minute;
    if ((hour <= 24 && hour >= 0) && (minute <= 60 && minute >= 0))
    {
        cout << endl;
        cout << endl;
        cout << "Ваше время: " << " " << hour << " " << ':' << " " << minute << " " << endl;
        cout << endl;
        time.minutes(hour, minute);
        cout << endl << endl;
    }
    else
    {
        cout << endl;
        cout << "Вы ввели недопустимые данные! ";
        cout << endl;
    }
    time.Pole(hour, minute);

    return 0;
}