#include <iostream>

using namespace std;

class abstr
{
public:
    virtual void Print() = 0; // чисто виртуальная функция
};



class Pair : public abstr
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

    void Print() override
    {
        cout << "Числа из класса 'Pair' - " << "(" << first << ',' << second << ")" << endl;
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
    while (first < 0)
    {
        cout << "Ввели отрицательное число, введите еще раз: ";
        in >> first;
    }
    cout << "Второе число = ";
    in >> second;
    while (second < 0)
    {
        cout << "Ввели отрицательное число, введите еще раз: ";
        in >> second;
    }
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

    void Print()
    {
        cout << "-----------------------------------";
        cout << endl << "Рубль: " << rub << endl;
        cout << endl;
        cout << "Копейка: " << kop << endl;
        cout << "-----------------------------------";
        cout << endl << endl;
    }   

};

bool operator>=(const Money& t1, const Money& t2)
{
    if (((t1.rub >= t2.rub - t2.rub) && t1.kop >= t2.kop - t2.kop) && (t2.rub >= t1.rub - t1.rub && t2.kop >= t1.kop - t1.kop))
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
    cout << endl << "Введите Money" << endl;
    cout << " rub = ";
    in >> f;
    while (f < 0)
    {
        cout << "Ввели отрицательное число, введите еще раз: ";
        in >> f;
    }
    cout << endl;
    cout << " kop = ";
    in >> s;
    while (s < 0)
    {
        cout << "Ввели отрицательное число, введите еще раз: ";
        in >> s;
    }
    cout << endl;
    x.Setter(f, s);
    return in;

}


class Vector
{
    friend ostream& operator<<(ostream& out, const Vector& l);
private:

    abstr** beg;
    int size;
    int cur;

public:

    Vector()
    {
        beg = 0;
        size = 0;
        cur = 0;
    }

    Vector(int n)
    {
        beg = new abstr * [n];
        cur = 0;
        size = n;
    }

    ~Vector()
    {
        if (beg != 0)
        {
            delete[] beg;
        }
        beg = 0;
    }

    void Add(abstr* p)
    {
        if (cur < size)
        {
            beg[cur] = p;
            cur++;
        }
    }

};


ostream& operator<<(ostream& out, const Vector& l)
{
    if (l.size == 0)
    {
        out << "Empty" << endl;
    }
    abstr** p = l.beg;

    for (int i = 0; i < l.cur; i++)
    {
        (*p)->Print();
        p++;
    }

    return out;
}


int main()
{
    setlocale(LC_ALL, "RUS");
    Vector l(5);
    Pair a;
    cin >> a;
    Money b;
    cin >> b;
    abstr* p = &a;
    l.Add(p);
    p = &b;
    l.Add(p);
    cout << l;
    return 0;
}