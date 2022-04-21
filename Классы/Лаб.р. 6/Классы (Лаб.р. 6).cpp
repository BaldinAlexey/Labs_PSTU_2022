#include<iostream>
#include<ctime>

using namespace std;

class Iterator
{
private:
	friend class  Vector;
	int* elem;
public:
	Iterator() { elem = 0; }
	void operator++() { ++elem; }
	void operator--() { --elem; }
	int& operator *() const { return*elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; }

};


class Vector
{
private:
	friend istream& operator>>(istream& in, Vector& tmp);
	friend ostream& operator<<(ostream& out, const Vector& tmp1);
	int size;
	int* data;
	Iterator beg;
	Iterator end;
public:
	Vector(int size)
	{
		this->size = size;
		data = new int[size];
		beg.elem = &data[0];
		end.elem = &data[size];
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
		tmp.beg.elem = &(tmp.data[0]);
		tmp.end.elem = &(tmp.data[size]);
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
			cout << endl << "Error" << endl;
		}
	}
	Iterator first() { return beg; }
	Iterator last() { return end; }

};

ostream& operator<<(ostream& out, const Vector& tmp1)
{
	cout << "{ ";
	for (int i = 0; i < tmp1.size; ++i)
	{
		out << tmp1.data[i] << " ";
	}
	cout << "}";
	return out;
}

istream& operator>>(istream& in, Vector& tmp)
{
	for (int i = 0; i < tmp.size; ++i)
	{
		in >> tmp.data[i];
	}
	return in;
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int size = 5;
	int k;

	Vector a(size);
	cout << "Введите элементы вектора a: " << endl;
	cin >> a;
	cout << endl;
	Iterator iter;
	cout << "Вектор a: " << a  << endl << endl;

	cout << "Введите индекс для поиска элемента: ";
	cin >> k;
	while (k < 0 || k >= size)
	{
		cout << "Индекс элемента не может быть '>=' количества чисел/или меньше нуля " << endl;
		cout << "Введите еще раз: ";
		cin >> k;
		cout << endl;
	}

	cout << endl << endl << "Число с выбранным индексом: " << a[k] << endl;

	cout << endl << "Длина вектора a: " << a() << endl << endl;

	Vector b(size);
	cout << "Введите элементы вектора b: " << endl;
	cin >> b;
	cout << endl;
	cout << "Вектор b: " << b;
	cout << endl;
	cout << endl << "Длина вектора b: " << b() << endl;

	Vector c = a * b;
	cout << endl << "Произведение равно : " << c << endl;
	cout << endl;

	int j = 0;
	cout << "Введите номер элемента, к которому будет осуществлён переход: ";
	int n;
	cin >> n;
	while (n > size || n <= 0)
	{
		cout << "Номер элемента не может быть больше количества чисел/или равен нулю/или отрицательным " << endl;
		cout << "Введите еще раз: ";
		cin >> n;
		cout << endl;
	}
	cout << endl;
	for (iter = c.first(); iter != c.last(); ++iter)
	{
		if (j != n)
		{
			--iter;
			while (j != n)
			{
				++iter;
				j++;
			}
		}
		else
		{
			break;
		}
		cout << "Элемент под " << n << " номером: " << *iter << " ";
		cout << endl << endl;

	}
	return 0;
}