#include<iostream>

using namespace std;

template<class T>
class Vector
{
	friend istream& operator>> <>(istream& in, Vector<T>& tmp);
private:
	T size;
	T* data;
public:
	Vector(T size)
	{
		this->size = size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = rand() % 100;
		}
	}

	Vector(const Vector& a)
	{
		size = a.size; 
		data = new T[size];
		for (int i = 0; i < size; i++) 
			data[i] = a.data[i];
	}

	virtual void show()
	{
		bool flag = true;
		cout << "Вектор : " << "{ ";
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
			if (i < size && flag)
			{
				cout << "; ";
				flag = false;
			}
		}
		cout << "}" << endl;
	}

	~Vector()
	{
		data = 0;
	}

	int& operator () () 
	{ 
		return size; 
	}

	Vector operator * (const Vector& other)
	{
		Vector<T> tmp(size);
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i] * other.data[i];
		}
		delete[]data;
		return tmp;
	}

	T& operator [](int index)
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else
		{
			cout << endl << "Ошибка " << endl;
		}
	}

	Vector& operator=(const Vector<T>& a)
	{
		if (this == &a)return *this; 
		size = a.size;
		if (data != 0) delete[]data; 
		data = new T[size];
		for (int i = 0; i < size; i++) 
			data[i] = a.data[i];
		return *this;
	}

};

template<class T>
istream& operator>>(istream& in, Vector<T>& tmp)
{
	for (int i = 0; i < tmp.size; ++i)
	{
		in >> tmp.data[i];
	}
	return in;
}


template<class T, class T2>
class Time
{
private:
	friend istream& operator>> (istream& in, Time<T, T2>& t);
	T min; 
	T sec;
public:
	Time(void)
	{
		min = sec = 0;
	}

	Time(int M, int S)
	{
		min = M;
		sec = S;
	}

	Time(const Time& t)
	{
		min = t.min;
		sec = t.sec;
	}

	Time& operator =(const Time& t)
	{
		min = t.min;
		sec = t.sec;
		return*this;
	}

	void show()
	{
		cout << "Время - " << min << " : " << sec << endl;
	}

	Time operator * (const Time& other)
	{
		Time<T, T2> tmp(12, 30);
		tmp.min = this->min * other.min;
		tmp.sec = this->sec * other.sec;
		return tmp;
	}
};

template<class T, class T2>
istream& operator>>(istream& in, Time<T,T2>& t)
{
	cout << "\nmin?"; in >> t.min;
	cout << "\nsec?"; in >> t.sec;
	return in;
}



int main()
{
	setlocale(LC_ALL, "rus");
	int size = 2;
	int k;

	Vector<int> a(size);
	cout << "Введите элементы вектора a: " << endl;
	cin >> a;
	cout << endl;
	a.show();
	cout << endl << "Длина вектора a: " << a() << endl << endl;
	cout << "Введите индекс для поиска элемента: ";
	cin >> k;
	while (k < 0 || k >= size)
	{
		cout << "Индекс элемента не может быть '>=' количества чисел/или меньше нуля " << endl;
		cout << "Введите еще раз: ";
		cin >> k;
		cout << endl;
	}

	cout << endl << "Число с выбранным индексом: " << a[k] << endl << endl;

	Vector<int> b(size);
	cout << "Введите элементы вектора b: " << endl;
	cin >> b;
	b.show();
	cout << endl << "Длина вектора b: " << b() << endl << endl;
	Vector<int> c(size);
	c = a * b;
	cout << "Произведение векторов - это ";
	c.show();
	cout << endl;

	Time<int, int> first(13, 10);
	first.show();
	cout << endl;

	Time<int, int> second(2, 2);
	second.show();
	cout << endl;

	Time<int, int> third(0, 0);
	third = first * second;
	third.show();
	cout << endl;
	cout << "Проверка перегрузки приравнивания: ";
	first = second;
	b.show();
	cout << endl << endl;
	cout << "Поиск по индексу: ";
	int index;
	cout << "Введите индекс: ";
	cin >> index;
	cout << endl;
	cout << "Координата по индексу: ";
	cout << a[index] << endl << endl;
	cout << "size = " << a() << endl;
	cout << endl;
	cout << "Еще время после перемножения: ";
	third = third * first;
	third.show();

	cout << endl << endl;
	return 0;
}
