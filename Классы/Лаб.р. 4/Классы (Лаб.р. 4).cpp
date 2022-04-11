#include <iostream>

using namespace std;

class Pair
{
protected:
    int first;
    int second;
public:

    Pair()
    {
        first = 1;
        second = 1;
    }

    Pair(int first, int second)
    {
        this->first = first;
        this->second = second;
    }


    virtual ~Pair()
    {
        cout << "Вызван деструктор для объекта: " << this << endl;
    }

    void Setter(int first, int second)
    {
        this->first = first;
        this->second = second;
    }

    Pair(const Pair& p)
    {
        first = p.first;
        second = p.second;
    }

    friend ostream& operator<<(ostream& out, const Pair& p);
    friend istream& operator>>(istream& in, const Pair& p);

    Pair& operator+(const Pair& t)
    {
        first = first + second;
        second = t.first + t.second;
        return *this;
    }
};



ostream& operator<<(ostream& out, const Pair& p)
{
    return (out << '(' << p.first << "," << p.second << ')');
}

istream& operator>>(istream& in, Pair& p)
{
    int first;
    int second;
    cout << "Введите Pair" << endl;
    cout << "Первое число = ";
    in >> first;
    cout << "Второе число = ";
    in >> second;
    p.Setter(first, second);
    return in;
}

class Money : public Pair
{
    friend bool operator>(const Money& t3, const Money& t4);
    friend bool operator>=(const Money& t1, const Money& t2);
    friend ostream& operator<<(ostream& out, const Money& w);
    friend istream& operator>>(istream& in, const Money& x);
private:

    int rub;
    int kop;

public:

    Money()
    {
        rub = 1;
        kop = 1;
    }

    Money(int fr, int sc)
    {
        this->rub = fr;
        this->kop = sc;
    }

    Money(const Money& pr)
    {
        rub = pr.rub;
        kop = pr.kop;
    }

    Money& operator-(const Money& q)
    {
        rub = rub - kop;
        kop = q.rub - q.kop;
        return *this;
    }

    Money& operator+(const Money& r)
    {
        rub = rub + kop;
        kop = r.rub + r.kop;
        return *this;
    }

    Money& operator/(const Money& v)
    {
        rub = rub / kop;
        kop = v.rub / v.kop;
        return *this;
    }

    void Setter(int f, int s)
    {
        rub = f;
        kop = s;
    }

    virtual ~Money()
    {
        cout << "Вызван деструктор для объекта : " << this << endl;
    }

};

bool operator>=(const Money& t1, const Money& t2)
{
    if (((t1.rub >= t2.rub - t2.rub) && t1.kop >= t2.kop - t2.kop) && ( t2.rub>= t1.rub - t1.rub && t2.kop >= t1.kop- t1.kop))
        return true;
    else
    {
        return false;
    }

}

bool operator>(const Money& t3, const Money& t4)
{
    if (((t3.rub > (t3.kop - 1)) && (t4.rub > (t4.kop - 1))) && ((t3.rub > -1 && t3.kop > -1) && (t4.rub > -1 && t4.kop > -1)))
        return true;
    else
    {
        return false;
    }

}

ostream& operator<<(ostream& out, const Money& w)
{
    return (out << '(' << w.rub << "," << w.kop << ')');
}

istream& operator>>(istream& in, Money& x)
{
    int f;
    int s;
    cout << "Введите Money" << endl;
    cout << " rub = ";
    in >> f;
    cout << " kop = ";
    in >> s;
    x.Setter(f, s);
    return in;

}

int main()
{
    setlocale(LC_ALL, "RUS");
    Pair A, B;
    cin >> A >> B;
    cout << endl;
    cout << "Выражение: ";
    cout << A << endl;
    cout << endl;
    cout << "Выражение: ";
    cout << B << endl;
    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Сумма чисел: ";
    cout << A + B << endl;
    cout << "--------------------------" << endl;
    cout << endl;

    Money elem1, elem2, elem3, elem4, elem5, elem6;

    cin >> elem1 >> elem2;
    if (elem1 >=elem2)
    {
        cout << endl;
        cout << "Выражение: ";
        cout << elem1 << endl;
        cout << endl;
        cout << "Выражение: ";
        cout << elem2 << endl;
        cout << endl;
        cin >> elem3 >> elem4;
        if (elem3 > elem4) 
        {
            cout << endl;
            cout << "Выражение: ";
            cout << elem3 << endl;
            cout << endl;
            cout << "Выражение: ";
            cout << elem4 << endl;
            cout << endl;

            cin >> elem5 >> elem6;
            if (elem5 >= elem6)
            {
                cout << endl;
                cout << "Выражение: ";
                cout << elem5 << endl;
                cout << endl;
                cout << "Выражение: ";
                cout << elem6 << endl;
                cout << endl;
                cout << "------------------------------------" << endl;
                cout << "Сложение: " << elem1 + elem2 << endl;
                cout << "Вычитание: " << elem3 - elem4 << endl;
                cout << "Деление: " << elem5 / elem6 << endl;
                cout << "------------------------------------" << endl;
                cout << endl << endl;
            }
            else { cout << endl << "Вы ввели отрицательное число" << endl; cout << endl; }
        }
        else { cout << endl << "Либо Вы ввели отрицательное число, либо Второе число меньше первого(Первое число должно быть больше, иначе будет отрицательная сумма ) " << endl; cout << endl; }
    }
    else { cout << endl << "Вы ввели отрицательное число" << endl; cout << endl; }
    return 0;
}