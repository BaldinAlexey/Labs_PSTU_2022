#include <iostream>

using namespace std;

struct list

{
	char data; // поле данных
	list* next; // указатель на следующий элемент
};

// создание первого узла

//init(значение для 1 узла)

list* init(char a) // number- значение первого узла

{

	list* lst;// выделение памяти под корень списка

	lst = new(list);

	lst->data = a; //закидываем значение которое нам необходимо

	lst->next = 0; //адрес зануляем так как только создали элемент

	//cout « "1 элемент создался, следующий указатель:"« lst->next «" значение:" « lst->data « endl;

	return(lst);

}

// добавление узла

// addelem(адрес последнего узла, значение нового узла)

list* addelem(list* lst, char a)

{

	list* temp, * endAdr;

	temp = new(list);

	endAdr = lst->next; // сохранение указателя на следующий узел

	lst->next = temp; // предыдущий узел указывает на создаваемый

	temp->data = a; // сохранение поля данных добавляемого узла

	temp->next = endAdr; // созданный узел указывает на следующий элемент

	//cout « "элемент создался, текущий указатель:" « lst->next « " следующий указатель:" « temp->next « " значение:" « temp->data « endl;

	return(temp); //адрес добавленного узла

}

// удаление узла

//deletelem(адрес удаляемого узла, адрес 1 узла)

list* deletelem(list* lst, list* root)

{
	list* temp;
	temp = root;

	while (temp->next != lst) // просматриваем список начиная с корня

	{ // пока не найдем узел, предшествующий lst
		temp = temp->next;
	}

	temp->next = lst->next; // переставляем указатель
	return(temp);

}

// вывод узлов

// listprint(адрес 1 узла)

void listprint(list* lst)

{
	list* endAdr;
	endAdr = lst;

	do {

		cout << " " << endAdr->data; // вывод значения элемента endAdr

		endAdr = endAdr->next; // переход к следующему узлу

	} while (endAdr != NULL);// условие окончания обхода

}

// вывод узлов

// listprint(адрес 1 узла)

void listprint_new(list* lst, char a)

{

	list* endAdr;
	endAdr = lst;
	char x;

	do {
		//проверка значения на совпадение

		if (endAdr->data == a)
		{
			cout << endl << "Введите новый элемент, который будет стоять после указанного : ";
			cin >> x;
			addelem(endAdr, x);
			endAdr = endAdr->next;
		}

		else 
		{
			endAdr = endAdr->next; // переход к следующему узлу
		}

	} while (endAdr != NULL); // условие окончания обхода

}

int main()

{
	setlocale(LC_ALL, "Russian");

	list* head, * endAdr; // head - адрес 1 узла, endAdr - адрес добавленного узла
	head = endAdr = 0;
	int col;
	char x;
	cout << "Введите количество элементов: ";
	cin >> col;
	cout << endl;
	//защита от неправильного ввода

	if (col > 0) {

		for (int i = 0; i < col; i++)

		{
			if (i == 0) 
			{
				cout << "Введите " << (i + 1) << " элемент: ";
				cin >> x;
				cout << endl;
				head = endAdr = init(x);
			}

			else 
			{
				cout << "Введите " << (i + 1) << " элемент: ";
				cin >> x;
				cout << endl;
				endAdr = addelem(endAdr, x);
			}
		}
		cout << "Выберете элемент, после которого поставить новый элемент : ";
		cin >> x;

		listprint_new(head, x);
		cout << endl;

		cout << "Список после преобразований:";
		listprint(head);
		cout << endl << endl;
	}
}
