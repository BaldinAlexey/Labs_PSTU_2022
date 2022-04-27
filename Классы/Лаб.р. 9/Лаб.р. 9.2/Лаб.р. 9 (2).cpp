#include<iostream>

using namespace std;

int max_size = 6;

class error
{
private:
	string msg;
public:
	error(string m)
	{
		msg = m;
	}
	void what()
	{
		cout << "Произошла ошибка: " << msg << endl;
	}
};

class Vector
{
private:
	friend istream& operator>>(istream& in, Vector& tmp);
	friend ostream& operator<<(ostream& out, const Vector& tmp1);
	int size;
	int* data;
public:

	Vector()
	{
		size = 0;
		data = 0;
	}

	Vector(int size)
	{
		if (size > max_size)
		{
			throw error("Недопустимый размер вектора!");
		}
		this->size = size;
		data = new int[size];
	}

	Vector(int size, int* d)
	{
		if (size > max_size)
		{
			throw error("Недопустимый размер вектора!");
		}
		this->size = size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = d[i];
		}
	}

	Vector(const Vector& other)
	{
		this->size = other.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}

	~Vector()
	{
	}

	int& operator () () { return size; }

	Vector operator *(const Vector& other)
	{
		Vector tmp(size);
		int* temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i] * other.data[i];
		}
		for (int i = 0; i < size; i++)
		{
			tmp.data[i] = temp[i];
		}
		delete[] temp;
		delete[]data;
		return tmp;
	}
	int& operator [](int index)
	{
		if (index >= 0 && index < size)
		{
			return data[index];
		}
		else
		{
			cout << endl;
			throw error("Недопустимый индекс");
		}
	}

	const Vector& operator = (const Vector& v)
	{
		if (this == &v) return *this;
		if (data != 0) delete[]data;
		size = v.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = v.data[i];
		}
			return *this;
	}
};


ostream& operator<<(ostream& out, const Vector& tmp1)
{
	cout << "{ ";
	for (int i = 0; i < max_size; ++i)
	{
		out << tmp1.data[i] << " ";
	}
	cout << "}";
	return out;
}

istream& operator>>(istream& in, Vector& tmp)
{
	for (int i = 0; i < max_size; ++i)
	{
		in >> tmp.data[i];
	}
	return in;
}




int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	try
	{
		int k;

		Vector a(max_size);
		cout << "Введите элементы вектора a: " << endl;
		cin >> a;
		cout << endl;
		cout << "Вектор a: " << a << endl << endl;

		cout << "Введите индекс для поиска элемента: ";
		cin >> k;
		cout << endl << "Число с выбранным индексом: " << a[k] << endl;
		cout << endl << "Длина вектора a: " << a() << endl << endl;

		Vector b(max_size);
		cout << "Введите элементы вектора b: " << endl;
		cin >> b;
		cout << endl;
		cout << "Вектор b: " << b;
		cout << endl;
		cout << endl << "Длина вектора b: " << b() << endl;

		Vector c = a * b;

		cout << endl << "Произведение векторов равно : " << c << endl;
		cout << endl;

		cout << "Введите номер элемента, к которому будет осуществлён переход: ";
		int n;
		cin >> n;
		while (n > max_size || n <= 0)
		{
			cout << "Номер элемента не может быть больше количества чисел/или равен нулю/или отрицательным " << endl;
			cout << "Введите еще раз: ";
			cin >> n;
			cout << endl;
		}
		cout << endl;

		int g = n;
		n--;
		cout << "Элемент под " << g << " номером: " << c[n];
			cout << endl << endl;
		
	}

	catch (error ER)
	{
		ER.what();
	}

	return 0;
}