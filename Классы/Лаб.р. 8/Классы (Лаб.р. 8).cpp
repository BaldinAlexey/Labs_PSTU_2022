#include<iostream>

using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmQuit = 101;

class Object
{
public:
	virtual void show_title() = 0;
	virtual void input() = 0;
	virtual void show() = 0;
};

struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int a;
		};
	};
};


class Print :public Object
{
protected:
	string author;
	string title;

public:
	
	Print(void)
	{
		title = " ";
		author = " ";
	}
	Print(string t, string a)
	{
		title = t;
		author = a;
	}
	Print(const Print& l)
	{
		title = l.title;
		author = l.author;
	}


	~Print(void)
	{
	}

	string Getter_for_title() { return title; }
	string Getter_for_author() { return author; }

	void Setter_for_title(string title) { this->title = title; }
	void Setter_for_author(string author) { this->author = author; }


	Print& operator= (const Print& p)
	{
		title = p.title;
		author = p.author;
		return *this;
	}

	void show()
	{
		cout << "Название: " << title << "\n";
		cout << "Автор: " << author << "\n\n";
	}

	void show_title()
	{
		cout << "Название: " << title << "\n";
	}

	void input()
	{
		cout << " Введите название: "; 
		cin >> this->title;
		cout << "Введите автора: "; 
		cin >> this->author;
		cout << "\n";
	}

};

class Magazin : public Print
{
protected:
	int str;
public:
	//конструкторы
	Magazin(void) : Print()
	{
		str = 0;
	}
	Magazin(string title, string author, int pages) : Print(title, author)
	{
		this->str = pages;
	}
	Magazin(const Magazin& s)
	{
		title = s.title;
		author = s.author;
		str = s.str;
	}

	//деструктор
	~Magazin(void)
	{
	}

	//селектор
	int getter1() { return  str; }

	//модификатор
	void setter1(int p) { str = p; }

	//перегрузка оператора присваивания
	Magazin& operator=(const Magazin& s)
	{
		title = s.title;
		author = s.author;
		str = s.str;
		return *this;
	}

	//метод для вывода атрибутов
	void show()
	{
		cout << "Название: " << title << "\n";
		cout << "Автор: " << author << "\n";
		cout << "Количество страниц: " << str << "\n\n";
	}

	//метод для ввода атрибутов
	void input()
	{
		cout << "Название: "; cin >> title;
		cout << "Автор: "; cin >> author;
		cout << "Количество страниц: "; cin >> str;
		cout << "\n";
	}
};

class Vector :public Magazin
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	//конструкторы
	Vector(void)
	{
		beg = 0;
		size = 0;
		cur = 0;
	}
	Vector(int n)
	{
		beg = new Object * [n];
		size = n;
		cur = 0;
	}
	Vector(const Vector& l)
	{
		beg = l.beg;
		size = l.size;
		cur = l.cur;
	}

	//деструктор
	~Vector(void)
	{
	}

	//добовление объекта на который указывает указатель р в список
	void Add()
	{
		Object* p;
		//выбор из объектов 2 возможных классов
		cout << "1.Print\n2.Magazin\n";
		cout << endl << "Выберите кнопку : " << endl;
		cout << endl;
		int y;
		cin >> y; 
		cout << "\n";

		if (y == 1)//добавление объекта класса print
		{
			Print* a = new (Print);
			a->input();
			p = a;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else if (y == 2)//добавление объекта класса magazin
		{
			Magazin* b = new (Magazin);
			b->input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
	}

	//удаление элемента из списка, но при этом память не освобождается
	void Del()
	{
		if (cur == 0) return;
		cur--;
	}


	//просмотр списка
	void AllInfo()
	{
		if (cur == 0) cout << "Пусто\n";
		Object** p = beg;//указатель на указатель типа Object
		for (int i = 0; i < cur; i++)
		{
			(*p)->show();//вызов метода Show() (позднее срабатывание)
			++p;//передвигаем указатель на след объект
		}
	}

	//просмотр элемента из списка
	void TitleInf()
	{
		if (cur == 0) cout << "Пусто\n";
		Object** p = beg;//указатель на указатель типа Object
		for (int i = 0; i < cur; i++)
		{
			(*p)->show_title();//вызов метода Show() (позднее срабатывание)
			++p;//передвигаем указатель на след объект
		}
	}

	//операция возвращающая размер списка
	int operator() ()
	{
		return cur;
	}

	void HandleEvent(const TEvent& event)
	{
		if (event.what == evMessage)
		{
			Object** p = beg;
			for (int i = 0; i < cur; i++)
			{
				(*p)->show();
				++p;
			}
		}
	}
};

class Dialog :public Vector
{
protected:
	int EndState;
public:

	Dialog() :Vector()
	{
		EndState = 0;
	}


	~Dialog()
	{
	}

	//очищение события
	void ClearEvent(TEvent& event)
	{
		event.what = evNothing;//пустое событие
	}

	//проверка EndState
	int Valid()
	{
		if (EndState == 0) return 0;
		else return 1;
	}

	//конец работы
	void EndExec()
	{
		EndState = 1;
	}

	//получения события
	void GetEvent(TEvent& event)
	{
		string OpInt = "m+-s?q";//коды операций
		string s;
		string param;

		char code;
		cout << "Ваше дейcтвие: ";
		cin >> s;
		cout << endl;
		code = s[0];//первый символ команды

		if (OpInt.find(code) >= 0)//является ли символ кодом операции
		{
			event.what = evMessage;
			switch (code)
			{
			case 'm':
				event.command = cmMake; break;//создать группу
			case '+':
				event.command = cmAdd; break;//добавить объект
			case '-':
				event.command = cmDel; break;//удалить объект
			case 's':
				event.command = cmShow; break;//вывести список
			case 'z':
				event.command = cmGet; break;//вывести атрибуты только одного объекта
			case 'q':
				event.command = cmQuit; break;//выход
			}

			//выделяем параметры команды если они есть
			if (s.length() > 1)
			{
				param = s.substr(1, s.length() - 1);
				int A = atoi(param.c_str());//преобразуем параметр в число
				event.a = A;//записываем параметр в сообщение
			}

		}
		else event.what = evNothing;//пустое событие
	}

	//обработчик событий
	void HandleEvent(TEvent& event)
	{
		if (event.what == evMessage)
		{
			switch (event.command)
			{
			case cmMake:
				size = event.a;
				beg = new Object * [size];
				cur = 0;
				ClearEvent(event);
				break;

			case cmAdd:
				Add();
				ClearEvent(event);
				break;

			case cmDel:
				Del();
				ClearEvent(event);
				break;

			case cmShow:
				cout << "-------------------------" << endl << endl;
				AllInfo();
				ClearEvent(event);
				cout << "-------------------------" << endl;
				break;

			case cmGet:		
				TitleInf();
				ClearEvent(event);
				break;

			case cmQuit:
				EndExec();
				ClearEvent(event);
				break;

			default:
				HandleEvent(event);
			}
		}
	}

	//главный цикл обработки событий
	int Execute()
	{
		TEvent event;
		do
		{
			EndState = 0;
			GetEvent(event);
			HandleEvent(event);
		} while (!Valid());
		return EndState;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "МЕНЮ: " << endl << endl;
	cout << "-----------------------------------" << endl;
	cout << endl << "1. Добавить: +\n2. Удалить: -\n3. Создать вектор: m\n4. Вывод инф. полей элементов: s\n5. Названия элементов: z\n6. Выход: q\n\n";
	cout << "-----------------------------------" << endl;
	cout << endl;
	cout << "Предлагаю создать Вектор(поля), чтобы после взаимодействовать c полями" << endl << endl;
	cout << "Для этого выберите символ 'm', но после символа ставьте цифру 1: если работа с печатным изданием" << endl << endl;
	cout << "или цифру 2: если работа с журналом " << endl << endl;
	Dialog D;
	D.Execute();
	return 0;
	cout << endl << endl;
}