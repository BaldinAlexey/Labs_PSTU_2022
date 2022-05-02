#include<iostream>
#include <string>

using namespace std;

int max_size = 6;

class Error
{
public:
	virtual void what() {};
};

class NumberError :public Error //ошибка в индексе вектора
{
protected:
string msg; 
public:
	NumberError() { msg = "Ошибка номера: "; }
	virtual void what() { cout << endl << msg; }
};

	class IndexError :public Error //ошибка в индексе вектора
	{
	protected:
	string msg; 
	public:
		IndexError() { msg = "Ошибка индекса: "; } 
		virtual void what() { cout << endl << endl << msg; }
	};

	class SizeError :public Error //ошибка в размере вектора
	{
	protected:
		string msg;
	public:
		SizeError() { msg = "Ошибка Размера: "; } 
		virtual void what() { cout << endl << msg; }
	};

	class MaxSizeError :public SizeError //превышение максимального размера
	{
	protected:
		string msg_;
	public:
		MaxSizeError() 
		{ 
			SizeError();
			msg_ = "Недопустимый размер вектора!"; 
		}
		virtual void what() { cout << endl << msg << msg_ << endl; }
	};

	class IndexError1 :public IndexError //индекс меньше нуля
	{
	protected:
	string msg_; 
	public:
		IndexError1() 
		{ 
			IndexError();
			msg_ = "Индекс меньше нуля! ";
		}
		virtual void what() { cout << endl << msg << msg_ << endl; }
	};

	class IndexError2 :public IndexError //индекс больше текущего размера вектора
	{
	protected:
		string msg_;
	public:
		IndexError2() 
		{ 
			IndexError();
			msg_ = "Индекс больше размера вектора ";
		}
		virtual void what() { cout << endl << msg << msg_ << endl; }
	};

	class NumberError1 :public NumberError
	{
	protected:
		string msg_;
	public:
		NumberError1() 
		{
			NumberError();
			msg_ = "Номер элемента не может быть больше количества чисел "; 
		}
		virtual void what() { cout << endl << msg << msg_ << endl; }
	};

	class NumberError2 :public NumberError
	{
	protected:
		string msg_;
	public:
		NumberError2() 
		{
			NumberError(); 
			msg_ = "Номер элемента не может быть отрицательным "; 
		}
		virtual void what() { cout << endl << msg << msg_ << endl; }
	};

	class NumberError3 :public NumberError
	{
	protected:
		string msg_;
	public:
		NumberError3()
		{
			NumberError();
			msg_ = "Номер элемента не может быть равен нулю ";
		}
		virtual void what() { cout << endl << msg << msg_ << endl; }
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
			throw MaxSizeError(); 
		}
		this->size = size;
		data = new int[size];
	}

	Vector(int size, int* d)
	{
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
		if (index < 0) throw IndexError1();
		if (index >= size) throw IndexError2();
		return data[index];
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
		cout << endl;
		if (n > max_size)
		{
			throw NumberError1();
			cout << endl;
		}
		else if (n < 0)
		{
			throw NumberError2();
			cout << endl;
		}
		else if (n == 0)
		{
			throw NumberError3();
			cout << endl;
		}

		int g = n;
		n--;
		cout << "Элемент под " << g << " номером: " << c[n];
		cout << endl << endl;

	}

	catch (Error &ER)
	{
		ER.what();
	}

	return 0;
}
